#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

string eval(string &str){
    reverse(str.begin(),str.end());
    stack<string>st;
    for(int i=0; i < str.size();i++){
        if(isdigit(str[i])){
            st.push(to_string(str[i] - '0'));
        }
        else{
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string new_exp = v1 + v2 + str[i]; 
            st.push(new_exp);
        }
    }
    return st.top();
}

int main(){
    string input = "*+31-15";
    string result = eval(input);
    cout << result << endl;
    return 0;
}