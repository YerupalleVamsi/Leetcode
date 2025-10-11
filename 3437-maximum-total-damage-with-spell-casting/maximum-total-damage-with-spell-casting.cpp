class Solution {
public:
    long long solve(vector<int>& power, int index, vector<long long>& dp) {
        if (index >= power.size()) return 0;
        if (dp[index] != -1) return dp[index];
        long long currPower = power[index];
        long long total = currPower;
        int next_idx= index + 1;
        while (next_idx < power.size() && power[next_idx] == currPower) {
            total += power[next_idx];
            next_idx++;
        }
        int skip = next_idx;
        while (skip < power.size() && power[skip] - currPower <= 2) skip++;

        long long take = total + solve(power, skip, dp);
        long long not_take = solve(power, next_idx, dp);

        return dp[index] = max(take, not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<long long> dp(power.size(), -1);
        return solve(power, 0, dp);
    }
};
