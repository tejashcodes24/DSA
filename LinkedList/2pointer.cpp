#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int val;
        Node * next;

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
            if(head == NULL){
                Node * newNode = new Node(val);
                head = newNode;
                return;
            }
            Node * newNode = new Node(val);
            Node * temp = head;

            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }

        void display(){
            Node * temp = head;
            while(temp != NULL){
                cout << temp -> val << "->";
                temp = temp -> next;
            }
            cout << "NULL";
        }
};

 // Code for calculating intersection of the nodes of two linked list.

bool equalLinkedList(Node * head1, Node * head2){
    Node * temp1 = head1;
    Node * temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 -> val != temp2 -> val){
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return (temp1 == NULL && temp2 == NULL);
}

int getLength(Node* head){
    int length = 0;
    Node * temp = head;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }
    return length;
}

Node * moveByk(Node * head,int k){
    Node * temp = head;
    int count = 0; 
    while(k--){
        temp = temp -> next;
    }
    return temp;
}

Node* intersectionNode(Node* head1, Node* head2){
    Node * ptr1 = head1;
    Node * ptr2 = head2;

    int ll1 = getLength(head1);
    int ll2 = getLength(head2);

    if(ll1 > ll2){
        int diff1 = ll1 - ll2;
        ptr1 = moveByk(head1, diff1);
        ptr2 = head2;
    }
    else{
        int diff2 = ll2 - ll1;
        ptr1 = head1;
        ptr2 = moveByk(head2, diff2);
    }

    while(ptr1){
        if(ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return NULL;
}
// code for removing kth node from the end of the linked list

void removeFromEnd(Node * &head, int k){
    Node * current = head;
    Node * current_plus_k = current;
    while(k--){
        current_plus_k = current_plus_k -> next;
    }
    if(current_plus_k == NULL){
        Node * temp = head;
        head = head -> next;
        free(temp);
        return;
    }
    while(current_plus_k -> next != NULL){
        current = current -> next;
        current_plus_k = current_plus_k -> next;
    }
    Node * temp = current -> next;

    current -> next = current -> next -> next;
    free(temp);
}

// merge two sorted linked list.

Node * mergeTwoSortedList(Node * &head1, Node * &head2){
    Node * dummy = new Node(0);
    Node * ptr1 = head1;
    Node * ptr2 = head2;
    Node * ptr3 = dummy;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 -> val <= ptr2 -> val){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
        }
        else{
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr3 = ptr3 -> next;
    }
    if(ptr1 != NULL){
        ptr3 -> next = ptr1;
    }
    if(ptr2 != NULL){
        ptr3 -> next = ptr2;
    }
    return dummy -> next;
}

// merge k sorted liinked list

Node * mergeKSortedList(vector<Node *> &lists){
    if(lists.size() == 0){
        return 0;
    }
    while(lists.size() > 1){
        Node * mergedList = mergeTwoSortedList(lists[0],lists[1]);
        lists.push_back(mergedList);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

// finding middle of the linked list

Node *middleOfLinkedlist(Node * &head){
    Node * slow = head;
    Node * fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

// Detect if a linked list is a cycle or not

bool detectCycle(Node *&head){
    Node * slow = head;
    Node * fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

// remove cycle from linked list

void removeCycle(Node *&head){  // assuming that Linked List contains cycle
    Node * slow = head;
    Node * fast = head;

    do{
        slow = slow -> next;
        fast = fast -> next -> next;
    }while(slow != fast);

    fast = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = NULL;
}
int main(){

    ListNode l1;
    l1.insertAtTail(3);
    l1.insertAtTail(5);
    l1.insertAtTail(9);
    l1.insertAtTail(11);
    l1.insertAtTail(14);
    l1.insertAtTail(15);
    l1.insertAtTail(16);
    l1.display();
    cout << endl;
    
    l1.head -> next -> next -> next -> next -> next -> next -> next = l1.head -> next -> next;
    cout << detectCycle(l1.head)<< endl;
    removeCycle(l1.head);
    cout << detectCycle(l1.head)<< endl;
    l1.display();


    // ListNode l2;
    // l2.insertAtTail(4);
    // l2.insertAtTail(6);
    // l2.insertAtTail(8);
    // l2.insertAtTail(10);
    // l2.display();
    // cout << endl;

    // ListNode l3;
    // l3.insertAtTail(1);
    // l3.insertAtTail(7);
    // l3.insertAtTail(12);
    // l3.display();
    // cout << endl;

    // ListNode mergedList;
    // vector<Node *> List;
    // List.push_back(l1.head);
    // List.push_back(l2.head);
    // List.push_back(l3.head);
    // mergedList.head = mergeKSortedList(List);
    // mergedList.display();
    
    
    
    // l2.head -> next -> next = l1.head -> next -> next -> next;
    // l2.display();
    // cout << endl;

    // Node * result = intersectionNode(l1.head, l2.head);

    // cout << result -> val;


    // removeFromEnd(l1.head,7);
    // l1.display();

    // l1.display();
    // cout << endl;
    // l2.display();
    // cout << endl;
    // cout << boolalpha << equalLinkedList(l1.head,l2.head);

    return 0;
}