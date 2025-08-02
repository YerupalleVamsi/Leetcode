class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp1, mpp2;
        set<int> s;
        int mini = INT_MAX; // to calc min element of both baskets

        for (int i : basket1) {
            mpp1[i]++;
            s.insert(i);
            mini = min(mini, i);
        }
        for (int i : basket2) {
            mpp2[i]++;
            s.insert(i);
            mini = min(mini, i);
        }

        unordered_map<int, int> target; // the target freq
        for (int i : s) {
            int sum = mpp1[i] + mpp2[i];
            if (sum & 1) return -1;
            target[i] = sum / 2;
        }

        vector<int> excess1, excess2; // the excess ones 
        for (auto& it : mpp1) {
            int extra = it.second - target[it.first];
            if (extra > 0) while (extra--) excess1.push_back(it.first);  // push excess elements 
        }
        for (auto& it : mpp2) {
            int extra = it.second - target[it.first];
            if (extra > 0) while (extra--) excess2.push_back(it.first); 
        }

       

        sort(excess1.begin(), excess1.end());
        sort(excess2.rbegin(), excess2.rend()); // sort in descending order 

        long long min_cost = 0;
        for (int i = 0; i < excess2.size(); i++) {
            int curr_min = min(excess1[i], excess2[i]);
            min_cost += min(curr_min, 2 * mini); 
        }

        return min_cost;
    }
};
