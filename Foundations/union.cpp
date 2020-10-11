#include <bits/stdc++.h>
using namespace std;
union Variant {
    char string[10];
    int integer;
    double floating_point;
};
// all members shares same memory block. Only one member valid at a time.
int main() {
    Variant v;
    v.integer = 42;
    cout << "Integer value = " << v.integer << "\n";
    v.floating_point = 10341.141;
    cout << "Floating point value = " << v.floating_point << "\n";
    cout << "Integer value = " << v.integer << "\n";
    return 0; 
}