#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack{
    Node* head;
    int capacity;
    int currentsize;
    public:
    Stack(int c){
        this -> capacity = c;
        this -> currentsize = 0;
        head = NULL;
    }

    bool isEmpty(){
        return this -> head == NULL;
    }

    bool isFull(){
        return this -> currentsize = this -> capacity;
    }

    void push(int data){
        if(this -> currentsize == this -> capacity){
            cout << "Overflow" << endl;
            return;
        }
        Node * new_node = new Node(data);
        new_node -> next = this -> head;
        this -> head = new_node;
        this -> currentsize++;
    }

    int pop(){
        if(this -> head == NULL){
            cout << "Underflow"<< endl;
            return INT_MIN;
        }
        Node * new_head = this -> head -> next;
        this -> head -> next = NULL;
        Node * deleteNode = this -> head;
        int result = deleteNode -> data;
        delete deleteNode;
        this -> head = new_head;

        return result;
    }
    int size(){
        return this -> currentsize;
    }

    int getTop(){
        if(this -> head == NULL){
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        return this -> head -> data;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop()<<endl;
    
    st.push(4);
    st.push(5);
    cout << st.getTop()<< endl;
    
    st.push(6);

    st.pop();
    st.pop();
    cout << st.getTop() << endl;
    return 0;
}