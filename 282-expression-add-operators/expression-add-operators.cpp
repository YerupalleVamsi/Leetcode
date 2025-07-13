class Solution {
public:
    void backtrack(string &num, int target, vector<string> &res, string curr, long long eval, int index, long long prev) {
        if (index == num.size()) {
            if (eval == target) {
                res.push_back(curr);
            }
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            // Skip numbers with leading zeros
            if (i != index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);  // Use stoll for long long

            if (index == 0) {
                // First number, no operator
                backtrack(num, target, res, part, val, i + 1, val);
            } else {
                backtrack(num, target, res, curr + "+" + part, eval + val, i + 1, val);
                backtrack(num, target, res, curr + "-" + part, eval - val, i + 1, -val);
                backtrack(num, target, res, curr + "*" + part, eval - prev + prev * val, i + 1, prev * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(num, target, res, "", 0, 0, 0);
        return res;
    }
};