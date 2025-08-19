class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
     long long res=0;
     int curr_streak=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            curr_streak++;
            res+=curr_streak;
        }
        else{
            curr_streak=0;
        }
     }  
     return res; 
    }
};