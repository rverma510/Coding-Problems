/*

With this policy, copying and assigning class instances to each other is possible without the danger 
of resource conflicts. The idea is to allocate proprietary memory in the destination object and then to 
copy the content to which the source object handle is pointing into the newly allocated block of memory. 
This way, the content is preserved during copy or assignment. However, this approach increases the memory 
demands and the uniqueness of the data is lost: After the deep copy has been made, two versions of the 
same resource exist in memory.

*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class DeepCopy {
    int *num;
  public: 
    DeepCopy(int val) {
        num = (int*)malloc(sizeof(int));
        *num = val;
        cout << "Resource allocated at : " << num << endl;
    }
    ~DeepCopy() {
        cout << "Resource deallocated at : " << num << endl;
        free(num);
    }
    DeepCopy(DeepCopy &source) {
        num = (int*)malloc(sizeof(int));
        *num = *source.num;
        cout << "Resource allocated at : " << num << endl;
    }
    DeepCopy &operator=(DeepCopy &source) {
        num = (int*)malloc(sizeof(int));
        *num = *source.num;
        cout << "Resource allocated at : " << num << endl;
        return *this;
    }
};

int main() {
    DeepCopy obj(13);
    DeepCopy obj1(obj);
    DeepCopy obj2 = obj1;

    return 0;
}