#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>
using namespace std;

stack<int> sorting(stack<int>&input){
    stack<int>temp;
    while(!input.empty()){
        int input_top = input.top();
        input.pop();
        while((!temp.empty()) && (input_top > temp.top())){
            int temp_top = temp.top();
            temp.pop();
            input.push(temp_top);
        }
        temp.push(input_top);
    }
    return temp;
}
//input: [34, 3, 31, 98, 92, 23]

// next greater element
// input: [4,6,3,1,0,9,5,6,7,3,2]

vector<int> nextGreaterElement(vector<int> &arr){
    stack<int>st;
    vector<int>output(arr.size(),-1);
    st.push(0);

    for(int i = 1; i < arr.size();i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
   return output;
}


vector<int> prevGreaterElement(vector<int> &arr){
    vector<int>output(arr.size(),-1);
    stack<int>st;
    int n = arr.size();
    reverse(arr.begin(),arr.end());
    st.push(0);

    for(int i=1; i < arr.size();i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            output[st.top()] = n - i - 1;   // because after reverse indexes will change
            st.pop();
        }
        st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(arr.begin(),arr.end());
    return output;
    
}

void display(stack<int>&st){
    while(!st.empty()){
        int top = st.top();
        st.pop();
        cout << top << endl;
    }
}
int main(){
    stack<int>st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    
    // stack<int>result = sorting(st);
    // display(result);
    cout << "Enter the size of the array" << endl;
    int size;
    cin >> size;
    vector<int>input;
    cout << "Enter the numbers: "<< endl;
    while(size--){
        int x;
        cin >> x;
        input.push_back(x);
    }
    //vector <int>result = nextGreaterElement(input);
    vector <int>result = prevGreaterElement(input);

    for(int i=0; i < result.size();i++){
        cout << i-result[i] << " ";
    }
}