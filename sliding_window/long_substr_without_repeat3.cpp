#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        set<char> st;
        int maxLength=0;
        for(int right=0; right<s.length(); right++) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
int main() {
    Solution s;
    string str = "abcabcbb";
    int result = s.lengthOfLongestSubstring(str);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}