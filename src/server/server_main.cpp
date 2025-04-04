#include <tcpserver.h>
#include <ThreadPool.h>
#include <conio.h>
map<string,int> route_socket;
int server_socket;
int epoll_fd;
string mysql_password;

//input password hiddenly
void setMysqlPassword(string &mysql_password){
    char pass[20]={0};
    int i=0;
    char c;//getchar
    while(1){
        c=c_getch();
        if (c == '\x0A') { //if Enter break
            break;
        }
        if (c == '\x7f') { //if BackSapce,delete one *
            if(i>0){
                cout<<"\b \b";
                --i;
            }
            
        }else {
            pass[i] = c;
            cout<<"*";
            if(i<20){
                i++;
            }
               
        }
    }
    mysql_password=pass;
}

//handle interacive attention signal
void signalHandler(int signum){
    cout<<"signal:"<<signum<<endl;
    cout<<"catch interactive attention signal,exit normally"<<endl;
    cout<<"close epoll sockets"<<endl;
    close(epoll_fd);
    cout<<"close server socket"<<endl;
    close(server_socket);
    cout<<"server exit completely"<<endl;
    exit(0);
}
int main(){
    server_socket=socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(SERVER_PORT);
    server_addr.sin_addr.s_addr=INADDR_ANY;
    if(bind(server_socket,(sockaddr *)&server_addr,sizeof(server_addr))<0){
        cerr<<"chat_server: main: server bind error"<<endl;
        exit(-1);
    }
    if(listen(server_socket,10)<0){
        cerr<<"chat_server: main: server listen error"<<endl;
        exit(-1);        
    }
    //epoll events
    epoll_fd=epoll_create(10);
    epoll_event socket_event,listen_event[MAX_LISTEN];
    socket_event.events=EPOLLIN | EPOLLET; //defalut:LT, use ET: EPOLLET|EPOLLIN
    socket_event.data.fd=server_socket;
    epoll_ctl(epoll_fd,EPOLL_CTL_ADD,server_socket,&socket_event);

    //set mysql_password
    cout<<"input the password of "<<SQL_USER<<":";
    setMysqlPassword(mysql_password);
    cout<<endl;
    while(1){
        signal(SIGINT,signalHandler);//if catch Ctrl C
        cout<<"waiting for connection..."<<endl;
        int event_num=epoll_wait(epoll_fd,listen_event,MAX_LISTEN,-1); //get the event number
        if(event_num<-1){                               
            break;  //if <0 then continue                                    
        }
        for(int i=0;i<event_num;i++){   //check all active event
            if(!(listen_event[i].events & (EPOLLIN|EPOLLET))){
                continue;
            }
            //if the event socket==server_socket, it is a new connection from one client
            if(listen_event[i].data.fd==server_socket){
                sockaddr_in client_addr;
                socklen_t clinet_size=sizeof(sockaddr_in);
                int client_socket=accept(server_socket,(sockaddr *)&client_addr,&clinet_size);
                if(client_socket<0){    //if connect failed,then pass this client,dicard the socket
                    continue;
                }else{
                    cout<<client_addr.sin_addr.s_addr<<":"<<client_addr.sin_port<<" connected"<<endl;
                }
                socket_event.events=EPOLLIN|EPOLLET;
                socket_event.data.fd=client_socket;
                if(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,client_socket,&socket_event)==-1){
                    cerr<<"client epoll_ctl error"<<endl;
                    raise(SIGINT);
                } //add new the connected socket to epoll events
                //insert route_socket,use hash value obain the client_socket
                route_socket.insert(pair<string,int>(to_string(client_socket),client_socket));
            }else{//if the active event!=server_socket，it must be client send one message 
                int session_socket=listen_event[i].data.fd; 	//get client_socket
                string recv_string;
                int ret=Recv(session_socket,recv_string);
                if(ret==0){
                //if return 0,that is client close the connection ,delete client socket from epoll events,and delete the route_ip key-value
                    epoll_ctl(epoll_fd,EPOLL_CTL_DEL,session_socket,NULL);
                    route_socket.erase(to_string(session_socket));//删除键值对
                    mid_Log_OUT(session_socket);//db log out
                    close(session_socket);
                    cout<<session_socket<<" client closed connection"<<endl;
                }else if(ret<0){//if ret<0,cerr
                    epoll_ctl(epoll_fd,EPOLL_CTL_DEL,session_socket,NULL);
                    close(session_socket);
                    cerr<<session_socket<<" client recv error"<<endl;
                }else{//the last must be recv one message:
                    cout<<"<Recv>:"<<recv_string<<endl;//TODEL
                    ThreadPool pool(10);
                    try{
                        pool.enqueue([recv_string,session_socket] {
                            parseJson(recv_string.c_str(),session_socket);
                        }
                        );
                    }catch(int e){
                        switch(e){
                            case ERROR_SQL_PASSWORD:
                                cerr<<"The Sql password is wrong"<<endl;
                            break;
                            case ERROR_SQL_CONNECTION:
                                cerr<<"Connect to MySql failed"<<endl;
                            break;
                            case ERROR_SQL_QUERY:
                                cerr<<"MySql Query failed"<<endl;
                            break;
                            case ERROR_SQL_RES_NULL:
                                cerr<<"MySql Resulst is null"<<endl;
                            break;
                        }
                    }
                    
                }
                }
            }
        }
}

