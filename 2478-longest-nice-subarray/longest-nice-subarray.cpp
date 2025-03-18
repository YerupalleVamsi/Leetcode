class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0;
        int maxsize=0;
        int sum=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            
           while((sum&nums[right])!=0)
           { sum^=nums[left];
            left++;
        }
        sum|=nums[right];
        maxsize=max(maxsize,right-left+1);
       }
        return maxsize;
    }
};