#include<bits/stdc++.h>
using namespace std;

string keypadHelper(int num){
	if(num == 2){
        return "abc";
    }
    else if(num == 3){
        return "def";
    }
    else if(num == 4){
        return "ghi";
    }
    else if(num == 5){
        return "jkl";
    }
    else if(num == 6){
        return "mno";
    }
    else if(num == 7){
        return "pqrs";
    }
    else if(num == 8){
        return "tuv";
    }
    else if(num == 9){
        return "wxyz";
    }
    else{
        return "";
    }
}

void printKeypad(int num, string output){
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    string s = keypadHelper(num % 10);
    for(int i = 0; i < s.size(); i++){
        printKeypad(num / 10, s[i] + output);
    }
}
int main(){
    int num;
    cin>>num;
    printKeypad(num, "");
    return 0;
}
