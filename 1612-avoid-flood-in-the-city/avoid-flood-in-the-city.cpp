class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, 1);
        set<int> dry; 
        unordered_map<int, int> last; // last day each lake got rain

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dry.insert(i);
            } else {
                res[i] = -1; 
                if (last.count(rains[i])) {
                    auto it = dry.lower_bound(last[rains[i]]); // >= 
                    if (it == dry.end()) return {}; 
                    res[*it] = rains[i]; 
                    dry.erase(it);
                }
                last[rains[i]] = i;
            }
        }
        return res;
    }
};
