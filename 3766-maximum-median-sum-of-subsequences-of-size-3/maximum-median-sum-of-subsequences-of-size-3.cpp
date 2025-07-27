class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
     long long medsum=0;
     sort(nums.begin(),nums.end());
     int n=nums.size();
     for(int i=nums.size()-2;i>=n/3;i-=2){
        medsum+=nums[i];
     }   
     return medsum;
    }
};