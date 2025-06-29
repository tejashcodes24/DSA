#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int calculate(int first,int second,char ch){
    if(ch == '+'){
        return first + second;
    }
    else if(ch == '-'){
        return first - second;
    }
    else if(ch == '*'){
        return first * second;
    }
    else{
        return first / second;
    }
}

int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    return -1;   
}

int evaluate(string &str){
    stack<char>ops;
    stack<int>num;
    for(int i=0; i < str.size();i++){
        if(isdigit(str[i])){
            num.push(str[i] - '0');
        }
        else if(str[i] == '('){
            ops.push(str[i]);
        }
        else if(str[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                char op = ops.top();
                ops.pop();

                int second = num.top();
                num.pop();
                int first = num.top();
                num.pop();
                int res = calculate(first,second,op);
                num.push(res);
            }
            if(!ops.empty()){ops.pop();}
        }
        else{
            while(!ops.empty() && precedence(ops.top()) >= precedence(str[i])){
                char op = ops.top();
                ops.pop();

                int second = num.top();
                num.pop();
                int first = num.top();
                num.pop();
                int res = calculate(first,second,op);
                num.push(res);
            }
            ops.push(str[i]);
        }
 
    }
    while(!ops.empty()){
            char c = ops.top();
            ops.pop();

            int second = num.top();
            num.pop();
            int first = num.top();
            num.pop();
            int res = calculate(first,second,c);
            num.push(res);
        }

        return num.top();
}

int main(){
    string str = "1+(2*(3-1))+2";
    int output = evaluate(str);
    cout << output;
    return 0;
}