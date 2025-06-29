#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int calculate(int first, int second, char ops){
    if(ops == '+'){
        return first + second;
    }
    else if(ops == '-'){
        return second - first;
    }
    else if(ops == '*'){
        return second * first;
    }
    else{
        return second / first;
    }
    return pow(first,second);
}
// prefix operations
int evaluate_postfix(string &pat){
    stack<int>st;
    for(int i=0; i < pat.size();i++){
        if(isdigit(pat[i])){
            st.push(pat[i] - '0');
        }
        else{
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            int res = calculate(first,second,pat[i]);
            st.push(res);
        }
    }
    return st.top();
}

//postfix operations
int evaluate_prefix(string &str){
    stack<int>st;
    for(int i=str.size()-1 ;i >= 0;i--){
        if(isdigit(str[i])){
            st.push(str[i] - '0');
        }
        else{
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            int result = calculate(first,second,str[i]);
            st.push(result);
        }
    }
    return st.top();
}

int main(){
    string abc = "-9+*531";
    int result = evaluate_prefix(abc);
    cout << result;
    return 0;
}