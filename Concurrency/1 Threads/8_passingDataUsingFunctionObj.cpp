#include <iostream>
#include <thread>
using namespace std;
class Vehicle {
  public:
    Vehicle(int id): _id(id) {}
    void operator()() {
        cout << "Vehicle object has been created with id " << _id << "\n";
    }

  private:
    int _id;
};
int main() {
    thread t = thread(Vehicle(1));
    cout << "Finished work in main\n";
    t.join();
    return 0;
}