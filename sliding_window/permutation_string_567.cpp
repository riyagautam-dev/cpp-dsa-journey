#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2) {
            return true;
        }
        for(int right=s1.length();right<s2.length();right++){
            freq2[s2[right] - 'a']++;
            freq2[s2[right - s1.length()] - 'a']--;
 if(freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
int main(){
    Solution obj;
    string s1="ab";
    string s2="ueooba";
     cout << boolalpha << obj.checkInclusion(s1, s2);

    return 0;
}

