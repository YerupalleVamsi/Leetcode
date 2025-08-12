class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int sq : squares) {
                if (sq > i) break;
                dp[i] = min(dp[i], dp[i - sq] + 1);
            }
        }

        return dp[n];
    }
};
