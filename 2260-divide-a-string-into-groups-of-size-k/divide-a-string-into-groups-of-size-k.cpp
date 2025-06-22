class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int j = 0;
        while (j < s.size()) {
            string curr = s.substr(j, k);
            if (curr.size() < k) {
                curr += string(k - curr.size(), fill);
            }
            ans.push_back(curr);
            j += k;
        }
        return ans;
    }
};
