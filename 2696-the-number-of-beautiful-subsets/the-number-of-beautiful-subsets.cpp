class Solution {
public:
    int backtrack(vector<int>&nums,int currpos,unordered_map<int,int> &hash, int k){
        if(currpos==nums.size()) return 1;
        int count=backtrack(nums,currpos+1,hash,k);
        if(hash[nums[currpos]-k]==0 && hash[nums[currpos]+k]==0){
            hash[nums[currpos]]++;
            count+=backtrack(nums,currpos+1,hash,k);
            hash[nums[currpos]]--;
        }
        return count;

            
        }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>hash;
        if(n==1) return 1;
       int ans=backtrack(nums,0,hash,k)-1;
       return ans;
    }
};