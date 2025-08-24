class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_len=0;
        int start=0;
        int zeros=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
            while(zeros>1){
                if(nums[start]==0){
                    zeros-=1;
                }
                start+=1;
            }
            max_len=max(max_len,i-start+1);

        }
        return max_len-1;
    }
};