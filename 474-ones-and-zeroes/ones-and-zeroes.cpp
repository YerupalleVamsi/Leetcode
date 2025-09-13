class Solution {
public:
    int tar1, tar2;
    vector<int> zeros, ones;
    vector<vector<vector<int>>> dp;

    int rec(vector<string>& strs, int zero, int one, int i) {
        if (i == strs.size()) { 
            return 0;
        }
        if (dp[i][zero][one] != -1) return dp[i][zero][one];

        int not_take = rec(strs, zero, one, i + 1);

        int take = INT_MIN;
        if (zero + zeros[i] <= tar1 && one + ones[i] <= tar2) { // 0/1 knapsack type problem
            take = 1+rec(strs, zero + zeros[i], one + ones[i], i + 1);
        }

        return dp[i][zero][one] = max(not_take, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        tar1 = m;
        tar2 = n;
        int sz = strs.size();
        zeros.resize(sz);
        ones.resize(sz);
        for (int i = 0; i < sz; i++) {
            int z = 0, o = 0;
            for (char c : strs[i]) {
                if (c == '0') z++;
                else o++;
            }
            zeros[i] = z;
            ones[i] = o;
        }
        dp.assign(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return rec(strs, 0, 0, 0);
    }
};
