class Solution {
public:
// we can solve it by bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        for(int num=0;num<(1<<n);num++){
            vector<int>sub;
            for(int i=0;i<n;i++){
                if((num&(1<<i))>0){
                    sub.push_back(nums[i]);
                }
            }
            res.push_back(sub);
        }
        return res;
    }
};