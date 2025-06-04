class Solution {
public:
bool valid(const string& a, const string& b) {
    if (a.length() != b.length()) return false;

    int diff = 0;
    for (size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            ++diff;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
         int n=words.size();
         vector<int>dp(n,1);
         vector<int>pre(n,-1);
         int max_len=1;
         int max_idx=0;
         for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
            if(groups[i]!=groups[j] && valid(words[i],words[j]))
            {
                  if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
            }
            if(dp[i]>max_len){
                max_len=dp[i];
                max_idx=i;
            }

            }
         }
         vector<string>ans;
         while(max_idx!=-1){
            ans.push_back(words[max_idx]);
            max_idx=pre[max_idx];
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};