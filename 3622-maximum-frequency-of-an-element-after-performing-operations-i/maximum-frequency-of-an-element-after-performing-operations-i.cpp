class Solution {
public:
    // int solve(vector<pair<int,int>>&p,int op,int tar){
    //     int freq=0;
    //     for(auto it:p){
    //         int l = it.first;
    //         int r = it.second;
    //         int curr =l+(r-l)/2;
    //         if(curr == tar){
    //             freq++;
    //         }
    //         else if(l<= tar && tar <=r && op>0){
    //             op--;
    //             freq++;
    //             if(op==0)return freq;
    //         }
    //     }
    //     return freq;
    // }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(),nums.end());
        int low = nums[0]-k;
        int high = nums.back()+k;
        vector<int>freq(high+1,0);
        for(int i:nums){
            freq[i]++;
        }

        for(int i=1;i<=high;i++){
            freq[i]+=freq[i-1];
        }
        int res=INT_MIN;
        for(int i=0;i<=high;i++){
            if(freq[i]==0) continue;
            int l = max(0,i-k);
            int r = min(high,i+k);
            int tar =  freq[i]-(i>0?freq[i-1]:0);
            int canmake = freq[r]-(l>0?freq[l-1]:0);
            res = max(res,tar + min(canmake-tar,numOperations));
        }
        return res;
    }
};