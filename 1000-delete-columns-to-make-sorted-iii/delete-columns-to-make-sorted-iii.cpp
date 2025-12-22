class Solution {
public:
    bool valid(vector<string>&strs,int i,int j){
      for (int r = 0; r < strs.size(); r++) {
         if (strs[r][i] < strs[r][j]) {
            return false;
            }
        }
    return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        vector<int>dp(m,1);
        for(int i=1;i<m;i++){
            for(int j=i-1;j>=0;j--){
                if(valid(strs,i,j)){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int maxi = INT_MIN;
        for(auto it:dp) maxi=max(it,maxi);
        return m-maxi;
    }
};