#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// minimum number of brackets need to remove to make the given racket balanced;

int minBracket(vector<char>str){
    stack<char>store;
    int count = 0;
    for(int i=0; i < str.size(); i++){
        if(str[i] == '('){
            store.push(str[i]);
        }
        else if(!store.empty()){
            store.pop();
        }
        else{
            count++;
        }
    }
    while(!store.empty()){
        count++;
        store.pop();
    }
    return count;
}

int main(){
    vector<char>str;
    str.push_back('(');
    str.push_back('(');
    str.push_back(')');
    str.push_back(')');
    str.push_back('(');
    str.push_back(')');
    str.push_back(')');
    str.push_back(')');
    str.push_back('(');

    int result = minBracket(str);
    cout << result;
    return 0;
}