
class Solution {
public:
    vector<vector<int>> dp;
    int recur(string &s, string &t, int idx, int j) {
        if (j == t.size()) return 1;        
        if (idx == s.size()) return 0;        
        if (dp[idx][j] != -1) return dp[idx][j];

        int take = 0;
        if (s[idx] == t[j]) {
            take = recur(s, t, idx+1, j+1); 
        }
        int not_take = recur(s, t, idx+1, j);

        return dp[idx][j] = take + not_take;
    }

    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;
        dp.assign(s.size(), vector<int>(t.size(), -1));
        return recur(s, t, 0, 0);
    }
};
