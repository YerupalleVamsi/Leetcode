class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int l=0 ,N = nums.size();
        int best = INT_MAX;
        int sum = 0;
        for(int r=0;r<N;r++){
            if(mpp[nums[r]]==0){
                sum+=nums[r];
            }
            mpp[nums[r]]++;
            while(sum>=k){
                best = min(best,r-l+1);
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) sum-=nums[l];
                l++;
            }
        }
        return best==INT_MAX? -1 : best;
    }
};