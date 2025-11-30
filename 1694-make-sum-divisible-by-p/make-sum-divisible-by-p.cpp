class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int i:nums)
        sum+=i;
        int k = sum%p;
        if(k==0) return 0;
//         (pref[i] - pref[j] + p) % p == k
//         pref[j] == (pref[i] - k + p) % p
        long long currsum=0;
        int best = nums.size();
        unordered_map<int,int>seen;
        seen[0]=-1;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            currsum%=p;
            int tar = (currsum-k+p)%p;
            if(seen.count(tar)){
                best = min(best,i-seen[tar]);
            }
            seen[currsum] = i;
        }
        return best == nums.size()?  -1: best;
    }
};