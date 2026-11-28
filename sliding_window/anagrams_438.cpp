
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return {};
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        vector<int> ans;

        for (int i = 0; i < p.length(); i++) {
            freq1[p[i] - 'a']++;
            freq2[s[i] - 'a']++;
        }

        if (freq1 == freq2) {
            ans.push_back(0);
        }

        int left = 0;

        for (int right = p.length(); right < s.length(); right++) {
            freq2[s[left] - 'a']--;
            freq2[s[right] - 'a']++;
            left++;

            if (freq1 == freq2) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};

int main() {
    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string p: ";
    cin >> p;

    Solution obj;

    vector<int> result = obj.findAnagrams(s, p);

    cout << "Anagram starting indices: ";

    for (int index : result) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
