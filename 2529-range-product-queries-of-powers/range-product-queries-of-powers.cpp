class Solution {
public:
    vector<long long> T; 
    const long long MOD = 1e9 + 7;
    void build(vector<long long>& arr, int tl, int tr, int node) {
        if (tl == tr) {
            T[node] = arr[tl] % MOD;
            return;
        }
        int tm = (tl + tr) / 2;
        build(arr, tl, tm, 2 * node);
        build(arr, tm + 1, tr, 2 * node + 1);
        T[node] = (T[2 * node] * T[2 * node + 1]) % MOD;
    }
    long long query(int l, int r, int tl, int tr, int node) {
        if (l > r) return 1; // identity element for * is 1 basic math nigga
        if (l == tl && r == tr) return T[node];
        int tm = (tl + tr) / 2;
        long long leftProduct = query(l, min(r, tm), tl, tm, 2 * node);
        long long rightProduct = query(max(l, tm + 1), r, tm + 1, tr, 2 * node + 1);
        return (leftProduct * rightProduct) % MOD;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<long long> arr;
        for (int i = 0; i < 32; i++) { // like this we extract the powers of 2
            if (n & (1 << i)) { // checking if the bit is set or not
                arr.push_back(1LL << i); // pushing the power of 2 of the set bit
            }
        }
        int N = arr.size();
        T.assign(4 * N, 1); 
        build(arr, 0, N - 1, 1);

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(query(l, r, 0, N - 1, 1));
        }
        return ans;
    }
};
