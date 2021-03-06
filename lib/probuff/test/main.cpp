#include <iostream>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <unistd.h>

#include <string>

#include <pthread.h>

#include <fstream>

#include "helloworld.pb.h"

 

using namespace std;

#define BUFFSIZE 1024

 

int main()

{

    GOOGLE_PROTOBUF_VERIFY_VERSION;

 

    //eg1, write file


    lm::helloworld msg1;

    msg1.set_id(1001);

    msg1.set_str("hello world");

 

    fstream output("./log", ios::out | ios::trunc | ios::binary);

    if (!msg1.SerializeToOstream(&output)) {

        cerr << "Failed to write msg." << endl;

        return -1;

    }

 

    output.close();

    cout << msg1.id() << endl;

    cout << msg1.str() << endl;

 

    //eg2, read file


    lm::helloworld msg2;

    fstream input("./log", ios::in | ios::binary);

    if (!input)

    {

        cerr << "open file failed!\n";

        return -1;

    }

 

    if (!msg2.ParseFromIstream(&input)) {

        cerr << "Parse file failed!" << endl;

        return -1;

    }

 

    input.close();

    cout << msg2.id() << endl;

    cout << msg2.str() << endl;

 

    //eg3, write buf, protobuf序列化


    lm::helloworld msg3;

    msg3.set_id(1002);

    msg3.set_str("good idea");

    char buf[BUFFSIZE];

    memset(buf, 0, BUFFSIZE);

    msg3.SerializeToArray(buf, BUFFSIZE);

 

    //eg4, read buf, protobuf反序列化


    lm::helloworld msg4;

    msg4.ParseFromArray(buf, BUFFSIZE);

    cout << msg4.id() << endl;

    cout << msg4.str() << endl;

 

    // Optional:  Delete all global objects allocated by libprotobuf.


    google::protobuf::ShutdownProtobufLibrary();

 

    return 0;

}

