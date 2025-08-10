class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&res,vector<bool>&vis,set<vector<int>>&s,vector<int>curr){
        if(curr.size()==nums.size() && s.find(curr)==s.end()){
            res.push_back(curr);
            s.insert(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=true;
                curr.push_back(nums[i]);
                backtrack(nums,res,vis,s,curr);
                curr.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        set<vector<int>>s;
        vector<bool>vis(n,false);
        backtrack(nums,res,vis,s,{});
        return res;
    }
};