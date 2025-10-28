class Solution {
public:
    int countValidSelections(vector<int>& nums) {
    if(nums.size()==1 && nums[0] == 0) return 2;
    int n = nums.size();
     vector<int>presum(n,0);
     presum[0] = nums[0];
     int sum = 0;
     for(int i:nums)
        sum+=i;
     for(int i=1;i<n;i++){
        presum[i] = presum[i-1] + nums[i];
     }  
     int cnt=0; 
    for(int i=0;i<nums.size();i++){
        int l = i==0? 0: presum[i-1];
        int r = sum - l;
        if(nums[i] == 0){
            if(l == r)
            cnt+=2;
            else if(abs(l-r)==1)
            cnt+=1;
        }
    }
    return cnt;

    }
};