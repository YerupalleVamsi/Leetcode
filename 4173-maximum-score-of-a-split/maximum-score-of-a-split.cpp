class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        int cur_min = INT_MAX;
        long long total =  accumulate(nums.begin(),nums.end(),0LL);
        long long score = LLONG_MIN;
        long long suff = 0;
        for(int i=n-1;i>0;i--){
            cur_min = min(nums[i],cur_min);
            suff+=nums[i];
            long long pref  = total - suff;
            score = max(score,pref - cur_min);
        }
        return score;
    }
};