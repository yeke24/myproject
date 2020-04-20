
cmake_minimum_required(VERSION 2.8)

 

project(pbtest)

 

#set(SRC .)

#查找当前目录下的所有源文件,并将名称保存到DIR_SRCS变量

aux_source_directory(. DIR_SRCS)

 

add_executable(${PROJECT_NAME} ${DIR_SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} protobuf)

