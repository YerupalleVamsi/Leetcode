class Solution {
public:
    int ans = 0;

    int dfs(int curr, int prev, vector<vector<int>>& adj, int k, vector<int>& values) {
        int res = 0;
        for (auto it : adj[curr]) {
            if (it != prev) {
                res += dfs(it, curr, adj, k, values);
            }
        }
        res += values[curr];
        if (res % k == 0) ans++;
        return res % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0, -1, adj, k, values);
        return ans;
    }
};
