class Solution {
public:
    void  backtrack(vector<vector<int>>&res,vector<int>&nums,vector<int>curr,vector<bool>&vis,int n){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                curr.push_back(nums[i]);
                backtrack(res,nums,curr,vis,n);
                curr.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        int n=nums.size();
        vector<bool>vis(n,false);
       backtrack(res,nums,curr,vis,n);
        return res;    
    }
};