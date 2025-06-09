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

void updateAtPosition(Node* &head, int k, int val){
    Node* temp = head;
    int count = 0;
    while(count != k){
        temp = temp -> next;
        count++;
    }

    temp -> val = val;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head -> next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* second_last = head;

    while(second_last -> next -> next != NULL){
        second_last = second_last -> next;
    }
    Node* temp = second_last -> next;
    second_last -> next = NULL;
    free(temp);
}

void deleteAtPosition(Node* &head, int pos){

    if(pos == 0){
        deleteAtHead(head);
        return;
    }
    Node * prev = head;
    for(int i = 0; i < pos - 1; i++){
        prev = prev -> next;
    }
    Node * temp = prev -> next;
    prev -> next = prev -> next -> next;
    free(temp);
}

void deleteAtAleternate(Node* &head){
    Node* currentNode = head;
    while(currentNode != NULL && currentNode -> next != NULL){
        Node * temp = currentNode -> next;
        currentNode->next = currentNode -> next -> next;
        free(temp);
        currentNode = currentNode -> next;
    }
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
    updateAtPosition(head,2,6);
    display(head);

    deleteAtHead(head);
    display(head);

    deleteAtTail(head);
    display(head);

    insertAtHead(head,4);
    insertAtHead(head,3);
    display(head);

    // deleteAtPosition(head,2);
    // display(head);

    deleteAtAleternate(head);
    display(head);
    
    return 0;
}