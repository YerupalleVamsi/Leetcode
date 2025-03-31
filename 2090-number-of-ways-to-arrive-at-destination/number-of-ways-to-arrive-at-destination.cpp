class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> gr;
        for (auto& it : roads) {
            gr[it[0]].emplace_back(it[1], it[2]);
            gr[it[1]].emplace_back(it[0], it[2]);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);
        constexpr int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node]) continue;  

            for (auto& [adjNode, weight] : gr[node]) {
                long long newDist = dis + weight;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.emplace(newDist, adjNode);
                    ways[adjNode] = ways[node];
                } else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
