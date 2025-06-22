#include<iostream>
using namespace std;
#include <stack>

// copy satck elements
stack <int> copyStack(stack <int> &input){
    stack <int>temp;
    while(!input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

void recursion(stack<int> &input, stack<int> &res){
    if(input.empty()){
        return;
    }
    int curr = input.top();
    input.pop();
    recursion(input,res);
    res.push(curr);
}

// insert at bottom of the stack.

void inserAtBottom(stack <int>&st, int val){  // time complexity : O(N)
    stack <int>temp;                          // space complexity: O(N)
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(val);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }    
}

void recursion_insertAtBottom(stack <int>&st, int val){  // time complexity: O(N);
    if(st.empty()){                                      // space commplexity: O(N);
        st.push(val);
        return;
    }
    int curr = st.top();
    st.pop();
    recursion_insertAtBottom(st,val);
    st.push(curr);
}

// insert at any index of a stack

void insertAtIdx(stack<int>&st,int idx, int val){
    stack<int>temp;
    int size = st.size();
    int count = 0;
    while(count < size - idx){
        count++;
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(val);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

// remove stack element at bottom;

void removeAtBottom(stack <int> &st){
    stack<int>temp;
    while(st.size() != 1){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}

void recursion_removeAtBottom(stack<int>&st){
    if(st.size() == 1){
        st.pop();
        return;
    }
    stack<int>temp;
    int curr = st.top();
    st.pop();
    recursion_removeAtBottom(st);
    st.push(curr);
}

// remove stack element at any index

void removeAtIdx(stack<int>&st,int idx){
    int n = st.size();
    int count = 0;
    stack<int>temp;
    while(count < n - idx - 1){
        count++;
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void recursion_removeAtIdx(stack<int>&st,int idx){
    if(st.size() - 1 == idx){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    recursion_removeAtIdx(st,idx);
    st.push(curr);
}

// reverse the original stack

void reverse(stack<int> &st){
    stack<int>t1,t2;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }
    while(!t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    while(!t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}

void recursion_reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    recursion_reverse(st);
    inserAtBottom(st,curr);
}

void display(stack<int> &st){
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            cout << curr << endl;
        }
    }
int main(){
    stack <int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);

    //recursion_insertAtBottom(input,200);
    //insertAtIdx(input,1,100);

    //removeAtBottom(input);
    //recursion_removeAtBottom(input);

    //recursion_removeAtIdx(input,1);

    //reverse(input);
    recursion_reverse(input);
    display(input);

    //stack <int> result = copyStack(input);
    // stack<int>result;
    // recursion(input,result);
    // while(!result.empty()){
    //     int val = result.top();
    //     result.pop();
    //     cout << val << endl;
    // }


    return 0;
}