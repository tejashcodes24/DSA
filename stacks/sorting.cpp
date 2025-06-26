#include<iostream>
#include<stack>
using namespace std;

stack<int> sorting(stack<int>&input){
    stack<int>temp;
    while(!input.empty()){
        int input_top = input.top();
        input.pop();
        while((!temp.empty()) && (input_top > temp.top())){
            int temp_top = temp.top();
            temp.pop();
            input.push(temp_top);
        }
        temp.push(input_top);
    }
    return temp;
}
//input: [34, 3, 31, 98, 92, 23]

void display(stack<int>&st){
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout << top << endl;
    }
}
int main(){
    stack<int>st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    
    stack<int>result = sorting(st);
    display(result);
}