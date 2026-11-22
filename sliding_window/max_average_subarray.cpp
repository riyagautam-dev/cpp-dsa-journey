#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
        }
        
         int maxSum=sum;
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k]+nums[i];
            maxSum=max(maxSum,sum);
        }
         
        
        return (double)maxSum/k;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,12,-5,-6,50,3};
    int k=4;
    cout<<s.findMaxAverage(nums,k)<<endl;
    return 0;
}