#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Queue{
    stack<int>st;
    public:
    Queue(){}

    void push(int x){
        this -> st.push(x);
    }

    void pop(){
        if(this -> st.empty()){return;}
        stack<int>temp;

        while(this -> st.size() > 1){
            int top = this -> st.top();
            this -> st.pop();
            temp.push(top);
        }

        st.pop();

        while(!temp.empty()){
            int top = temp.top();
            temp.pop();
            this -> st.push(top);
        }
    }

    int front(){
        if(this -> st.empty())return -1;
        stack<int>temp;
        while(this -> st.size() > 1){
            int top = st.top();
            this -> st.pop();
            temp.push(top);
        }
        int result = st.top();
        while(!temp.empty()){
            int top = temp.top();
            temp.pop();
            this -> st.push(top);
        }
        return result;
    }

    bool isEmpty(){
        return this -> st.empty();
    }
};

int main(){

    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    int top = qu.front();

    qu.pop();
    qu.push(40);

    qu.pop();

    while(!qu.isEmpty()){
        cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}