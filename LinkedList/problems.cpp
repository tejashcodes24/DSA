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

class ListNode{
    public:
        Node * head;

        ListNode(){
            head = NULL;
        }
        void insertAtTail(int val){
            Node* new_node = new Node(val);
            if(head == NULL){
                head = new_node;
                return;
            }

            Node* temp = head;

            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = new_node;
        }

        void display(){
            Node * temp = head;
            while(temp != NULL){
                cout << temp -> val << "->";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }

        void deleteAtAlternate(){
            Node* currentNode = head;
            while(currentNode != NULL && currentNode -> next != NULL){
                Node * temp = currentNode -> next;
                currentNode -> next  = currentNode -> next -> next;
                free(temp);
                currentNode  = currentNode -> next;
            }
        }
};

void removeDuplicate(Node* &head){
    Node* currentNode = head;
    while(currentNode != NULL){
        while(currentNode -> next != NULL && currentNode -> val == currentNode -> next -> val){
            Node * temp = currentNode -> next;
            currentNode -> next = currentNode -> next -> next;
            free(temp);
        }
        
        currentNode = currentNode -> next;
    }
}

void reversePrint(Node * &head){

    // base case
    if(head == NULL){
        return;
    }

    // recursive case
    reversePrint(head -> next);
    cout << head -> val << " ";
}

Node * reverseLinkList(Node *&head){
    Node * prev = NULL;
    Node *current_node = head;
    Node * next_node = NULL;

    while(current_node != NULL){
        next_node = current_node -> next;
        current_node -> next = prev;
        prev = current_node;
        current_node = next_node;
    }
    Node* new_head = prev;
    return new_head;
}

Node * reverseRecursion(Node* &head){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    //recursive case
    Node* new_head = reverseRecursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}

Node * reversebyK(Node* &head,int k){
    Node * prev = NULL;
    Node * current = head;
    int count = 0;

    while(current != NULL && count < k){
        Node * next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(current != NULL){
        Node * new_head = reversebyK(current,k);
        head -> next = new_head;
    }
    return prev;
}

int main(){
    ListNode ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);

    ll.display();

    // ll.deleteAtAlternate();
    // ll.display();

    //reversePrint(ll.head);

    // reverseLinkList(ll.head);
    // ll.display();

    // ll.head = reverseRecursion(ll.head);
    // ll.display();

    ll.head = reversebyK(ll.head,2);
    ll.display();

    return 0;
}