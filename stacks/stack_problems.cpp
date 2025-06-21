#include<iostream>
using namespace std;
#include <stack>

stack <int> copyStack(stack <int> &input){
    stack <int>temp;
    while(!input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void recursion(stack<int> &input, stack<int> &res){
    if(input.empty()){
        return;
    }
    int curr = input.top();
    input.pop();
    recursion(input,res);
    res.push(curr);
}

int main(){
    stack <int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);

    //stack <int> result = copyStack(input);
    stack<int>result;
    recursion(input,result);
    while(!result.empty()){
        int val = result.top();
        result.pop();
        cout << val << endl;
    }
    return 0;
}