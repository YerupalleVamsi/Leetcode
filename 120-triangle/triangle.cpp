// int rec(vector<vector<int>>&nums,int curr_idx,int col,vector<vector<int>>&dp){
//        if(col <0 || col >=nums[curr_idx].size()) return INT_MAX;
//        if(dp[curr_idx][col]!=-1) return dp[curr_idx][col];
//        if(curr_idx==nums.size()-1)return nums[curr_idx][col];
//         int l=rec(nums,curr_idx+1,col,dp);
//         int r=rec(nums,curr_idx+1,col+1,dp);
//         return dp[curr_idx][col]=nums[curr_idx][col]+min(l,r);

//     }
//     int minimumTotal(vector<vector<int>>&nums) {
//         if(nums.size()==1) return nums[0][0];
//         int n=nums.size();
//         int m=nums[n-1].size();
//        vector<vector<int>>dp(n+1,vector<int>(n,-1));
//         return rec(nums,0,0,dp);
//     } 

// O(n*m)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(triangle.back()); // we dont need to calc the last row so we take it as base 
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};