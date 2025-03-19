#ifndef SIGNAL_MACRO_H
    #define SIGNAL__MACRO_H
//=====signal======
//SQL0-9
// #define SQL_FALSE 0
// #define SQL_TRUE 1
// #define SQL_ACCOUNT_REGISTED 2
// #define SQL_ACCOUNT_NOT_REGISTED 3
// #define SQL_WRONG_PASSWORD 4
// #define SQL_ACCOUNT_ONLINE 5
// #define SQL_BUFFER_ADD_CONTACT 6
// #define SQL_BUFFER_SEND_MESSAGE 7
// #define SQL_AGREE_ADD 8
// #define SQL_REJECT_ADD 9
enum SQLSignal{
    SQL_FALSE=0,
    SQL_TRUE,
    SQL_ACCOUNT_REGISTED,
    SQL_ACCOUNT_NOT_REGISTED,
    SQL_WRONG_PASSWORD,
    SQL_ACCOUNT_ONLINE,
    SQL_BUFFER_ADD_CONTACT,
    SQL_BUFFER_SEND_MESSAGE,
    SQL_AGREE_ADD,
    SQL_REJECT_ADD
};
//===========socket signal======
//10-29
// #define SOCKET_LOG_UP 10
// #define SOCKET_LOG_IN 11
// #define SOCKET_ADD_CONTACT 12
// #define SOCKET_ANSWER_ADD 13
// #define SOCKET_SELECT_WHEN_START 14
// #define SOCKET_MESSAGE 15
// #define SOCKET_EDIT_CONTACT 16
// #define SOCKET_GET_RPOFILE 17
// #define SOCKET_CLEAR_MESSAGE_HISTORY 18
enum SOCKETSingal{
    SOCKET_LOG_UP=10,
    SOCKET_LOG_IN,
    SOCKET_ADD_CONTACT,
    SOCKET_ANSWER_ADD,
    SOCKET_SELECT_WHEN_START,
    SOCKET_MESSAGE,
    SOCKET_EDIT_CONTACT,
    SOCKET_GET_RPOFILE,
    SOCKET_CLEAR_MESSAGE_HISTORY
};
//SERVER signal
//30->
// #define SERVER_FALSE 30
// #define SERVER_TRUE 31
// #define SERVER_ACCOUNT_REGISTED 32
// #define SERVER_ACCOUNT_NOT_REGISTED 33
// #define SERVER_WRONG_PASSWORD 34
// #define SERVER_ACCOUNT_ONLINE 35
// #define SERVER_BUFFER_ADD_CONTACT 36
// #define SERVER_BUFFER_SEND_MESSAGE 37
// #define SERVER_ADD_CONTACT_REQUEST 38
// #define SERVER_AGREE_ADD_CONTACT  39
// #define SERVER_REJECT_ADD_CONTACT  40
// #define SERVER_ANSWER_YES 41
// #define SERVER_ANSWER_NO 42
// #define SERVER_CONTACT_LIST 43
// #define SERVER_MESSAGE 44
// #define SERVER_EDIT_NICKNAME  45
// #define SERVER_DELETE_CONTACT  46
// #define SERVER_GROUP_MESSAGE 47
// #define SERVER_TEXT_MESSAGE 48
// #define SERVER_IMAGE_MESSAGE  49
enum SERVERSignal{
    SERVER_FALSE=30,
    SERVER_TRUE,
    SERVER_ACCOUNT_REGISTED,
    SERVER_ACCOUNT_NOT_REGISTED,
    SERVER_WRONG_PASSWORD,
    SERVER_ACCOUNT_ONLINE,
    SERVER_BUFFER_ADD_CONTACT,
    SERVER_BUFFER_SEND_MESSAGE,
    SERVER_ADD_CONTACT_REQUEST,
    SERVER_AGREE_ADD_CONTACT,
    SERVER_REJECT_ADD_CONTACT,
    SERVER_ANSWER_YES,
    SERVER_ANSWER_NO,
    SERVER_CONTACT_LIST,
    SERVER_MESSAGE,
    SERVER_EDIT_NICKNAME,
    SERVER_DELETE_CONTACT,
    SERVER_GROUP_MESSAGE,
    SERVER_TEXT_MESSAGE,
    SERVER_IMAGE_MESSAGE
};
//======macro======
#define SOCKET_SIZE 2048
#define MAX_LISTEN 1024
#endif