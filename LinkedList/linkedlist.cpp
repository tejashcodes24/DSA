#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head,int data){  //Time Complexity: O(1) 
    Node* new_node = new Node(data);
    new_node -> next = head;
    head = new_node;
}

void insertAtTail(Node* &head,int val){ // Time Complexity: O(n) 
    Node*new_node = new Node(val);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp -> next = new_node;
}

void insertAtPosition(Node* &head,int pos,int val){
    if(pos == 0){
        insertAtHead(head, val);
        return;
    }
    Node* new_node = new Node(val);
    Node* temp = head;
    for(int i=0; i < pos - 1 && temp != NULL; i++){
        temp = temp -> next;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}
void display(Node* head){
    Node*temp = head;
    while(temp != NULL){
       cout<<temp->val<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,3);
    display(head);
    insertAtTail(head,4);
    display(head);
    insertAtPosition(head,1,5);
    display(head);
    
    return 0;
}