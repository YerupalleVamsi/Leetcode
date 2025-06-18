class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int nsq=1;
        int mini=nums[0];
        for(int maxi=0;maxi<nums.size();maxi++){
            if(nums[maxi]-mini>k){
                nsq++;
                mini=nums[maxi];
            }
            
        }
        return nsq;

    }
};