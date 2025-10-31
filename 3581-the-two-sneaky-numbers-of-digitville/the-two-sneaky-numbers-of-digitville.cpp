class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>s;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            if(!s.count(nums[i])){
                s.insert(nums[i]);
            }
            else{
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};