#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> slidingWindow(vector<int>nums,int k){
    deque<int>dq;
    vector<int>result;
    for(int i=0; i < k; i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    result.push_back(nums[dq.front()]);

    for(int i = k; i < nums.size(); i++){
        int curr = nums[i];
        if(dq.front() == (i - k))dq.pop_front();
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        result.push_back(nums[dq.front()]);
    }

    return result;
}

int main(){
    vector<int>input;
    int size;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    cout << "Enter the elements of the array" << endl;
    for(int i=0 ; i < size; i++){
        int n;
        cin >> n;
        input.push_back(n);
    }
    cout << endl;
    vector<int>output = slidingWindow(input,3);
    for(int i=0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    return 0;
}