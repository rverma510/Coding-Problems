#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::string;
using std::ifstream;
int main() {
    ifstream my_file;
    my_file.open("1_board.txt");
    if (my_file) {
        cout << "Stream successfully created.\n";
        string line;
        while (getline(my_file, line)) {
            cout << line << "\n";
        }
    }
}