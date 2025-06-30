#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
    public:
    Queue(){
        this -> front = -1;
        this -> back = -1;
    }

    void enqueue(int data){
        this -> v.push_back(data);
        this -> back++;
        if(this -> back == 0){
            this -> front = 0;
        }
    }

    void dequeue(){
        if(this -> front == this -> back){
            this -> front = -1;
            this -> back = -1;
            this -> v.clear();
        }
        else{
            this -> front++;
        }
    }

    int getFront(){
        if(this -> front == -1){
            return -1;
        }
        return this -> v[this -> front];
    }

    bool isEmpty(){
        return this -> front == -1;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();

    q.enqueue(40);
    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.dequeue();
    }
}

