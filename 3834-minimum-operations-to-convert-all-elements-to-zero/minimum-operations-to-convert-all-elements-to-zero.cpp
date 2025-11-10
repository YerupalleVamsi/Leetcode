class Solution {
public:
    int n;
    vector<long long> tree;
    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end)
            tree[node] = nums[start];
        else {
            int mid = (start + end) / 2;
            build(nums, 2 * node + 1, start, mid);
            build(nums, 2 * node + 2, mid + 1, end);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    long long query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return LLONG_MAX;
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(
            query(2 * node + 1, start, mid, l, r),
            query(2 * node + 2, mid + 1, end, l, r)
        );
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
        int op = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            if (mpp.find(nums[i]) == mpp.end()) {
                op++;
            }
            else if (query(0,0,n-1,mpp[nums[i]]+1,i-1) < nums[i]) {
                op++;
            }
            mpp[nums[i]] = i;
        }
        return op;
    }
};
