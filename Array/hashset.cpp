#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char>set;
        int left = 0,right = 0;
        int maxLength = 0;
        for(right =0 ; right < s.size(); right++){
            // If the character is already in the set, we need to move the left pointer
            while(set.find(s[right]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            // Add the current character to the set
            set.insert(s[right]);
            // Update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
}

;
int main() {
    Solution solution;
    string s = "abcabcbb";
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}
// g++ hashset.cpp -o hashset.exe
// ./hashset.exe
// Output: Length of the longest substring without repeating characters: 3.