class Solution {
public:
    int countHillValley(vector<int>& arr) {
        int cnt=0;
        // hill --> nums[i]>nums[i+1] && nums[i]> nums[i-1]
        // valley --> nums[i]<nums[i+1] && nums[i] < nums[i-1]
            vector<int> nums;
    for (int val : arr) {
        if (nums.empty() || nums.back() != val) {
            nums.push_back(val);
        }
    }
        int i=1;
        while(i<nums.size()-1){
            if(nums[i] > nums[i+1] && nums[i]>nums[i-1]){
                cnt++;
            }
            else if(nums[i]<nums[i+1] && nums[i] < nums[i-1]){
                cnt++;
            }
            if(nums[i]==nums[i+1]){
                
            }
            i++;
        }
        return cnt;
    }
};