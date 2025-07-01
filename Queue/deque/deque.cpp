#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    
    d.push_front(0);
    d.push_front(33);

    while(!d.empty()){
        cout << d.front() << " ";
        d.pop_front();
    }
    return 0;
}