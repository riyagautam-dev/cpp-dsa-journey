#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int zerocount=0;
        int maxlength=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right] == 0){
                  zerocount++;
               }
            while(zerocount>k){
                if(nums[left]==0){
                    zerocount--;
                    
                }
                left++;
            }
            int length = right - left + 1;
            maxlength = max(maxlength, length);


        }
   return maxlength;


        
    }
};
int main(){
Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << s.longestOnes(nums, k);

    return 0;
}
