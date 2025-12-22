class Solution {
public:
    typedef long long ll;
    long long beautifulSubarrays(vector<int>& nums) {
    ll curr=0,cnt=0;
    unordered_map<ll,ll>seen;
    seen[0]=1;
    for(int r=0;r<nums.size();r++){
        curr^=nums[r];
        if(seen.count(curr)){
            cnt+=seen[curr];
        }
        seen[curr]++;
    }
     return cnt;   
    }
};