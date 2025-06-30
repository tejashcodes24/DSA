#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        this -> data = val;
        this -> next = NULL;
    }
};

class Queue{
    Node * head;
    Node * tail;
    int size;
    public:
    Queue(){
        this -> head = NULL;
        this -> tail = NULL;
        this -> size = 0;
    }

    void enqueue(int data){
        Node * newNode = new Node(data);
        if(this -> head == NULL){
            this -> head = newNode;
            this -> tail = newNode;
        }
        else{
            this -> tail -> next = newNode;
            this -> tail = newNode;
        }
        this -> size ++;
        
    }

    void dequeue(){
        if(this -> head == NULL){
            return;
        }
        Node *oldhead = this -> head;
        Node *newhead = this -> head -> next;
        this -> head -> next = NULL;
        this -> head = newhead;
        if(this -> head == NULL){
            this -> tail == NULL;
        }
        delete oldhead;
    }

    int getSize(){
        return this -> size;
    }

    bool isEmpty(){
        return this -> head == NULL;
    }

    int front(){
        if(this -> head == NULL){return -1;}
        return this -> head -> data;
    }
};

int main(){
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);

    qu.dequeue();

    qu.enqueue(40);

    while(!qu.isEmpty()){
        cout << qu.front() << " ";
        qu.dequeue();
    }

    return 0;
}