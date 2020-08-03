#include <iostream>
#include <thread>
using namespace std;

int main() {    
    int id = 0;
    auto f0 = [&id]() { 
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "a) In thread, call by reference " << id << endl;
    };
    thread t0(f0);

    auto f1 = [id]() mutable {
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "b) In thread, call by value " << id << endl;
    };
    thread t1(f1);

    ++id;
    cout << "c) In main, call by value " << id << endl;
    
    t0.join();
    t1.join();
    
    return 0;



    return 0;
}