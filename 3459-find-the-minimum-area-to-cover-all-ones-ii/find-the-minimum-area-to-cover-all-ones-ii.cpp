#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getarea(vector<vector<int>>& grid, int sr, int er, int sc, int ec) {
        int minr = INT_MAX, minc = INT_MAX;
        int maxr = INT_MIN, maxc = INT_MIN;
        bool found = false;
        for (int i = sr; i <= er; ++i) {
            for (int j = sc; j <= ec; ++j) {
                if (grid[i][j] == 1) {
                    found = true;
                    minr = min(minr, i);
                    minc = min(minc, j);
                    maxr = max(maxr, i);
                    maxc = max(maxc, j);
                }
            }
        }

        if (!found) return 0;
        return (maxr - minr + 1) * (maxc - minc + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();      
        int m = grid[0].size();  
        int min_sum = INT_MAX;

        for (int r = 0; r < n - 1; r++) {
            for (int c = 0; c < m - 1; c++) {
                int A1 = getarea(grid, 0, r, 0, m - 1); // top-part
                int A2 = getarea(grid, r + 1, n - 1, 0, c); // bottom-left
                int A3 = getarea(grid, r + 1, n - 1, c + 1, m - 1); // bottom-right
                min_sum = min(min_sum, A1 + A2 + A3);

                int A4 = getarea(grid, r + 1, n - 1, 0, m - 1); // bottom-part
                int A5 = getarea(grid, 0, r, 0, c);             // top-left
                int A6 = getarea(grid, 0, r, c + 1, m - 1);     // top-right
                min_sum = min(min_sum, A4 + A5 + A6);
            }
        }  
        for (int c = 0; c < m - 1; c++) {
            for (int r = 0; r < n - 1; r++) {
                int A1 = getarea(grid, 0, n - 1, 0, c); // left vertical
                int A2 = getarea(grid, 0, r, c + 1, m - 1); // top-right
                int A3 = getarea(grid, r + 1, n - 1, c + 1, m - 1); // bottom -right
                min_sum = min(min_sum, A1 + A2 + A3);


                int A4 = getarea(grid, 0, n - 1, c + 1, m - 1); // right vertical
                int A5 = getarea(grid, 0, r, 0, c);             // top-left
                int A6 = getarea(grid, r + 1, n - 1, 0, c);     // bottom-left
                min_sum = min(min_sum, A4 + A5 + A6);
            }
        }

        for (int r1 = 0; r1 < n - 2; r1++) {
            for (int r2 = r1 + 1; r2 < n - 1; r2++) {
                int top = getarea(grid, 0, r1, 0, m - 1);
                int mid = getarea(grid, r1 + 1, r2, 0, m - 1);
                int bottom = getarea(grid, r2 + 1, n - 1, 0, m - 1);
                min_sum = min(min_sum, top + mid + bottom);
            }
        }

        for (int c1 = 0; c1 < m - 2; c1++) {
            for (int c2 = c1 + 1; c2 < m - 1; c2++) {
                int left = getarea(grid, 0, n - 1, 0, c1);
                int mid = getarea(grid, 0, n - 1, c1 + 1, c2);
                int right = getarea(grid, 0, n - 1, c2 + 1, m - 1);
                min_sum = min(min_sum, left + mid + right);
            }
        }

        return min_sum;
    }
};
