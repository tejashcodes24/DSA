#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<int>qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);

    stack<int>st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        qu.push(ele);
    }

    while(!qu.empty()){
        cout << qu.front() << " ";
        qu.pop();
    }
}
