#include<iostream>
using namespace std;

class Stack{
    int capacity;
    int *arr;
    int top;

    public:
    Stack(int c){
        this -> capacity = c;
        arr = new int[c];
        this -> top = -1;
    }

    void push(int data){
        if(this -> top == this -> capacity - 1){
            cout << "Stack Overflow";
            return;
        }
        this -> top++;
        this -> arr[top] = data;
    }
    
    int pop(){
        if(this -> top == -1){
            cout << "Stack Underflow\n";
            return INT_MIN;
        }
        this->top--;
    }

    int getTop(){
        if(this -> top == -1){
            cout << "Stack Underflow\n";
            return INT_MIN;
        }
        return this -> arr[this -> top];
    }

    bool isEmpty(){
        return this -> top == -1;
    }

    int size(){
        return this -> top + 1;
    }

    bool isFull(){
        return this -> top == this -> capacity - 1;
    }
};

int main(){
    Stack st(3);
    st.push(1);
    st.push(2);
    cout << st.getTop() <<endl;
    st.pop();
    st.push(3);
    st.push(4);
    
    st.push(5);
    cout << endl;
    cout << st.getTop() << endl;
    return 0;
}