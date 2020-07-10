#include<iostream>
#include<string>
#include<sstream>
using std::cout;
using std::string;
using std::istringstream;
int main() {
    string s("1,2,3");
    istringstream my_stream(s);
    int n;
    char c;
    while (my_stream >> n >> c) {
        cout << "Stream successful : "<< n << " : " << c << "\n";
    }
    cout << "Stream failed.";
    return 0;
}