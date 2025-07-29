class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // or never decreases 
        // we have to find the max_distance of set bits from the curr index
        // 10^9 ---> max 30 bits needed
        int n=nums.size();
        vector<int>seen(30,0);
        vector<int>res(n,1);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<30;b++){
                if(nums[i]&(1<<b)){
                    seen[b]=i;
                }
                res[i]=max(res[i],seen[b]-i+1);
            }
        }
        return res;
    }
};