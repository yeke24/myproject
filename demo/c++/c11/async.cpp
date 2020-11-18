#include <iostream>       // std::cout
#include <future>         // std::async, std::future
 
using namespace std;
 
//这是一个用于检验素数的函数
bool is_prime(int x) {
    cout << "Calculating. Please, wait...\n";
    for (int i = 2; i < x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
 
int main()
{
    //异步地调用函数is_prime(313222313)
    future<bool> fut = async(is_prime, 313222313);
 
    cout << "Checking whether 313222313 is prime.\n";
    
    // 等待is_prime返回
    bool ret = fut.get();     
 
    if (ret) {
        cout << "It is prime!\n";
    } else {
        cout << "It is not prime.\n";
    }
 
    return 0;
}