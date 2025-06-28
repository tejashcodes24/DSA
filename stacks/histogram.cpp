#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int histogram(vector<int> &arr){
    stack<int>st;
    st.push(0);
    int ans = INT_MIN;
    for(int i=1; i < arr.size(); i++){   // We are finding next smaller element;
        while(!st.empty() && arr[st.top()] > arr[i]){
            int el = arr[st.top()];
            st.pop();
            int nei = i;
            int pei = (st.empty()) ? -1 : st.top();
            ans = max(ans,el*(nei - pei - 1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int el = arr[st.top()];
        st.pop();
        int nei = arr.size();
        int pei = (st.empty()) ? -1 : st.top();
        ans = max(ans,el*(nei - pei - 1));
    }
    return ans;

}

int main(){
    vector<int>input;
    cout << "Enter the size of the element" << endl;
    int size;
    cin >> size;
    cout << "Enter elements:" << endl;
    while(size--){
        int n;
        cin >> n;
        input.push_back(n);
    }

    int max_area = histogram(input);
    cout << max_area;
    return 0;
}