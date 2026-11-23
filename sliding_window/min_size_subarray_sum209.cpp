#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
    public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0; 
        int sum=0;
        int minLength=INT_MAX;
        for(int right=0; right<nums.size(); right++) {
            sum += nums[right];
            while(sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int result = s.minSubArrayLen(target, nums);
    cout << "Minimum length of subarray with sum >= " << target << ": " << result << endl;
    return 0;
}