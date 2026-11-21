#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
                
            }
        }
        return j+1;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,1,2};
    int newLength=s.removeDuplicates(nums);
    cout<<"New length: "<<newLength<<endl;
    cout<<"Modified array: ";
    for(int i=0;i<newLength;i++){
        cout<<nums[i]<<" ";
    }
  
    return 0;
}