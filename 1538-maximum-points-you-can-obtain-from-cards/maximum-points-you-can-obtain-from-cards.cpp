class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int leftSum = 0;
        // Take first k elements from left
        for (int i = 0; i < k; i++) {
            leftSum += cp[i];
        }
        int maxScore = leftSum;
        // Now, for each i from 1 to k:
        // replace cp[k-i] from left with cp[n-i] from right
        for (int i = 1; i <= k; i++) {
            leftSum -= cp[k - i];     // remove from end of current left segment
            leftSum += cp[n - i];     // add from right
            maxScore = max(maxScore, leftSum);
        }

        return maxScore;
    }
};
