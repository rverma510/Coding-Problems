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

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int smallAns = keypad(num / 10, output);
	string s = keypadHelper(num % 10);
    int ans = s.size() * smallAns;
    for(int i = 1; i < s.size(); i++){
        for(int j = 0; j < smallAns; j++){
            output[j + i * smallAns] = output[j] + s[i];
        }
    }
    for(int i = 0; i < smallAns; i++){
        output[i] = output[i] + s[0];
    }
	return ans;
}
void printKeypad(int num){
    string *output = new string[200000];
	int ans = keypad(num, output);
    for(int i = 0; i < ans; i++){
        cout<<output[i]<<endl;
    }
}
int main(){
    int num;
    cin>>num;
    printKeypad(num);
    return 0;
}
