/*

The last ownership policy we will be discussing in this course implements a shared ownership behavior. 
The idea is to perform a copy or assignment similar to the default behavior, i.e. copying the handle 
instead of the content (as with a shallow copy) while at the same time keeping track of the number of 
instances that also point to the same resource. Each time an instance goes out of scope, the counter is 
decremented. Once the last object is about to be deleted, it can safely deallocate the memory resource.

*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class SharedCopy {
  private:
    int *num;
    static int cnt;
  public:
    SharedCopy();
    ~SharedCopy();
    SharedCopy(SharedCopy &);
};

int SharedCopy::cnt = 0;


SharedCopy::SharedCopy() {
    num = (int*)malloc(sizeof(int));
    cnt++;
    cout << "Memory Allocated : " << num << endl;
}

SharedCopy::~SharedCopy() {
    cnt--;
    if (!cnt) {
        cout << "Memory Deallocated : " << num << endl;
        free(num);
    }
}

SharedCopy::SharedCopy(SharedCopy &source) {
    num = source.num;
    cnt++;
    cout << "Memory copied : " << num << endl;
}

int main() {
    SharedCopy source;
    SharedCopy destination1(source);
    SharedCopy destination2(source);
    SharedCopy destination3(source);
    
    return 0;
}