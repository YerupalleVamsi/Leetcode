class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long currlen = 0;
        long long currsum = 0;
        int count = 0;

        // Traverse from the end (least significant bit)
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                // Compute 2^currlen safely as a long long
                if (currlen < 63 && (currsum + (1LL << currlen)) <= k) {
                    currsum += (1LL << currlen);
                    count++;
                }
            } else {
                count++;
            }
            currlen++;
        }

        return count;
    }
};
