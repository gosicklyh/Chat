cmake_minimum_required(VERSION 3.22.1)
project(chat_server LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# 设置构建路径
set(build_path ${PROJECT_SOURCE_DIR}/build/)
set(LIBRARY_OUTPUT_DIRECTORY ${build_path}/lib/)
set(CMAKE_CACHEFILE_DIR ${build_path}/build_cache/)
set(include_path ${PROJECT_SOURCE_DIR}/include/)
#import existed libs
link_directories(${PROJECT_SOURCE_DIR}/lib)

# MySQL 配置
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_library(MYSQL_LIBRARY NAMES mariadb mariadbclient mysqlclient)
if(NOT MYSQL_LIBRARY)
    message(FATAL_ERROR "MariaDB/MySQL client library not found")
endif()

# 服务器配置
set(SERVER_PORT 8888)
set(SQL_HOST "127.0.0.1")
set(SQL_USER "chatuser")
set(SQL_DATABASE "chat") 
set(SQL_PORT 3306)
set(SQL_PASS_PATH "${PROJECT_SOURCE_DIR}/build/pass.dat")

# 配置头文件
configure_file(${include_path}/db/server.h.in ${include_path}/db/server.h)

# 包含目录
include_directories(
    ${PROJECT_SOURCE_DIR}/include/db/
    ${PROJECT_SOURCE_DIR}/include/encode/
    ${PROJECT_SOURCE_DIR}/include/mysql/
    ${PROJECT_SOURCE_DIR}/include/tcpserver/
    ${PROJECT_SOURCE_DIR}/include/json/
    ${PROJECT_SOURCE_DIR}/include/threadpool/
)

# 构建设置
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose build type" FORCE)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

# 构建共享库
add_library(TcpServer SHARED 
    ./Source/encode/base64.cpp
    ./Source/encode/md5.cpp
    ./Source/encode/conio.cpp
    ./Source/db/db_contact.cpp
    ./Source/db/db_global.cpp
    ./Source/db/db_log.cpp
    ./Source/db/db_message.cpp
    ./Source/tcpserver/tcpserver_contact.cpp
    ./Source/tcpserver/tcpserver_global.cpp
    ./Source/tcpserver/tcpserver_log.cpp
    ./Source/tcpserver/tcpserver_message.cpp
)

#===============debug release==============

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#==========================================
# 构建可执行文件
add_executable(server_main server_main.cpp)

# 链接库
target_link_libraries(server_main 
    PRIVATE 
    TcpServer 
    ${MYSQL_LIBRARY}
)

message("Build chat_server: ${CMAKE_BUILD_TYPE}\n")