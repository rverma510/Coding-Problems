/*

This policy states that whenever a resource management object is copied, the resource handle is 
transferred from the source pointer to the destination pointer. In the process, the source pointer is 
set to nullptr to make ownership exclusive. At any time, the resource handle belongs only to a single 
object, which is responsible for its deletion when it is no longer needed.

*/
#include <iostream>
#include <stdlib.h>
using namespace std;
class ExclusiveCopy {
    int *num;
  public:
    ExclusiveCopy() {
        num = (int*)malloc(sizeof(int));
        cout << "Memory Allocated\n"; 
    }
    ~ExclusiveCopy() {
        if (num != nullptr) {
            free(num);
            cout << "Memory Deallocated\n";
        }
    }
    ExclusiveCopy(ExclusiveCopy &source) {
        num = source.num;
        source.num = nullptr;
    }
    ExclusiveCopy &operator =(ExclusiveCopy source) {
        num = source.num;
        source.num = nullptr;
        return *this;
    }
};

int main() {
    ExclusiveCopy source;
    ExclusiveCopy destination(source);
    return 0;
}