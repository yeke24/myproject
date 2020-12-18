#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "proto/cuba/hello/hello.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hello::HelloRequest;
using hello::HelloReply;
using hello::HelloService;

class HelloClient {
 public:
  HelloClient(std::shared_ptr<Channel> channel) : stub_(HelloService::NewStub(channel)) {}

  std::string Salute(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;

    Status status = stub_->Salute(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      return "Rpc failed";
    }
  }

 private:
  std::unique_ptr<HelloService::Stub> stub_;
};

void printTime(std::string msg, clock_t begin) {
    auto end = clock();
    double elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    std::cout.precision(17);
    std::cout << msg << " " << std::fixed <<"Elapsed time: " << elapsed_sec << std::endl;
}

void doStuff(HelloClient *client, int index) {
    auto begin = clock();

    std::string user("Fidel");
    std::string reply = client->Salute(user);
    std::cout << "Greeter received: " << reply << std::endl;

    std::stringstream msg;
    msg << "Message " << index;
    printTime(msg.str(), begin);
}

int main(int argc, char** argv) {
  auto begin = clock();
  HelloClient client(
      grpc::CreateChannel("localhost:50051", grpc::InsecureCredentials()));

  for (auto i = 1; i <= 50; i ++) {
    doStuff(&client, i);
  }

  printTime("Total time for 50 rpcs", begin);

  return 0;
}