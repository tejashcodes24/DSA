#include<iostream>
#include<stack>
using namespace std;
 // using pop operation optimization
class Queue{
    stack<int>st;
    public:
    Queue(){}

    void push(int x){
        if(st.empty()){
            st.push(x);
        }
        else{
            stack<int>tmp;
            while(!st.empty()){
                int top = st.top();
                st.pop();
                tmp.push(top);
            }
            tmp.push(x);
            while(!tmp.empty()){
                int top = tmp.top();
                tmp.pop();
                st.push(top);
            }
        }
    }

    void pop(){
        if(st.empty()){
            return;
        }
        st.pop();
    }

    int front(){
        return st.top();
    }

    bool isEmpty(){
        return st.empty();
    }
};

int main(){
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);

    qu.pop();

    qu.push(40);

    while(!qu.isEmpty()){
        cout << qu.front() << " ";
        qu.pop();
    }
}
