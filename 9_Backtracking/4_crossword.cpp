#include<bits/stdc++.h>
using namespace std;
#define n 10
typedef long long int ll;

void printCrossword(char **cross){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<cross[i][j];
        }
        cout<<endl;
    }
}

bool isValidVertical(char **cross, string word, int r, int c){
    if(word.size() > n - r)
        return false;
    for(int i = 0; i < word.size(); i++){
        if(cross[i + r][c] == '+' || (cross[i + r][c] != '-' && cross[i + r][c] != word[i]))
            return false;
    }
    return true;
}

bool isValidHorizontal(char **cross, string word, int r, int c){
    if(word.size() > n - c)
        return false;
    for(int i = 0; i < word.size(); i++){
        if(cross[r][i + c] == '+' || (cross[r][i + c] != '-' && cross[r][i + c] != word[i]))
            return false;
    }
    return true;
}

void setVertical(char **cross, string word, bool *helper, int r, int c){
    for(int i = 0; i < word.length(); i++){
        if(cross[i + r][c] == '-'){
            cross[i + r][c] = word[i];
            helper[i] = true;
        }
    }
}

void setHorizontal(char **cross, string word, bool *helper, int r, int c){
    for(int i = 0; i < word.length(); i++){
        if(cross[r][i + c] == '-'){
            cross[r][i + c] = word[i];
            helper[i] = true;
        }
    }
}

void unSetVertical(char **cross, bool *helper, int size, int r, int c){
    for(int i = 0; i < size; i++){
        if(helper[i]){
            cross[i + r][c] = '-';
        }
    }
}

void unSetHorizontal(char **cross, bool *helper, int size, int r, int c){
    for(int i = 0; i < size; i++){
        if(helper[i]){
            cross[r][i + c] = '-';
        }
    }
}

bool solveCrossword(char **cross, vector<string> words, int index){
    if(index == words.size()){
        printCrossword(cross);
        return true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cross[i][j] == '-' || cross[i][j] == words[index][0]){
                if(isValidVertical(cross, words[index], i, j)){
                    bool *helper = new bool[words[index].size()];
                    for(int i = 0; i < words[index].size();i++)
                        helper[i] = false;
                    setVertical(cross, words[index], helper, i, j);
                    if(solveCrossword(cross, words, index + 1)){
                        return true;
                    }
                    unSetVertical(cross, helper, words[index].size(), i, j);
                    delete helper;
                }
                if(isValidHorizontal(cross, words[index], i, j)){
                    bool *helper = new bool[words[index].size()];
                    for(int i = 0; i < words[index].size();i++)
                        helper[i] = false;
                    setHorizontal(cross, words[index], helper, i, j);
                    if(solveCrossword(cross, words, index + 1)){
                        return true;
                    }
                    unSetHorizontal(cross, helper, words[index].size(), i, j);
                    delete helper;
                }

            }
        }
    }
    return false;
}

int main(){
    char **cross = new char*[n];
    string s;
    vector<string> words;
    int start = 0;
    for(int i = 0; i < n; i++){
        cross[i] = new char[n];
        for(int j = 0; j < n; j++)
            cin>>cross[i][j];
    }
    cin>>s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ';'){
            words.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }
    words.push_back(s.substr(start));
    solveCrossword(cross, words, 0);
    return 0;
}

/*
----------
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
++++++++++
CALIFORNIA

*/
