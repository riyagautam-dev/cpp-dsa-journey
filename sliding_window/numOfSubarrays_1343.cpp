#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int sum=0;
       int count=0; 
       for(int i=0;i<k;i++){
        sum=sum+arr[i];
        
       }
       double average = (double)sum / k;
       
       if(average >= threshold) {
       count++;
}
       
       for(int i=k;i<arr.size();i++){
        sum=sum-arr[i-k]+arr[i];
        average = (double)sum / k;
        if(average >= threshold) {
        count++;

       }
     
       }
       return count;
    
    }
};
int main(){
    Solution s;
    vector<int> arr={2,2,2,2,5,5,5,8};
    int k=3;
    int threshold=4;
    cout<<s.numOfSubarrays(arr,k,threshold)<<endl;
    return 0;
}
