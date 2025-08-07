class Solution {
public:
    vector<vector<int>> dp2;
    vector<vector<int>> dp3;
    vector<vector<int>> fruits;
    int n;

    int solveright(int i, int j) {
        if (i >= n || j < 0 || j >= n || i >= j) return 0;
        if (i == n - 1 && j == n - 1) return fruits[i][j];
        if (dp2[i][j] != -1) return dp2[i][j];
        int curr = fruits[i][j];
        int max_fruits = 0;
        max_fruits = max(max_fruits, curr + solveright(i + 1, j - 1));
        max_fruits = max(max_fruits, curr + solveright(i + 1, j));
        max_fruits = max(max_fruits, curr + solveright(i + 1, j + 1));
        return dp2[i][j] = max_fruits;
    }

    int solveleft(int i, int j) {
        if (i < 0 || j >= n || i >= n || i <= j) return 0;
        if (i == n - 1 && j == n - 1) return fruits[i][j];
        if (dp3[i][j] != -1) return dp3[i][j];
        int curr = fruits[i][j];
        int max_fruits = 0;
        max_fruits = max(max_fruits, curr + solveleft(i - 1, j + 1));
        max_fruits = max(max_fruits, curr + solveleft(i, j + 1));
        max_fruits = max(max_fruits, curr + solveleft(i + 1, j + 1));
        return dp3[i][j] = max_fruits;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int total = 0;
        this->fruits = fruits;
        n = fruits.size();
        dp2 = vector<vector<int>>(n, vector<int>(n, -1));
        dp3 = vector<vector<int>>(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            total += fruits[i][i]; // collect diagonal
        }

        total += solveright(0, n - 1);
        total += solveleft(n - 1, 0);
        return total;
    }
};