class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit=0;
        int curr_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int cost = nums[i]-curr_min;
            // cout << cost << " ";
            if(cost>0){
                profit+=cost;
                curr_min = INT_MAX;
            }
            curr_min=min(curr_min,nums[i]);
        }
        return profit;
    }
};