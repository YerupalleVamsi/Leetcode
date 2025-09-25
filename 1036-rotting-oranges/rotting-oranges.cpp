class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int fresh=0;
        queue<pair<int,int>>q;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==2){
                   q.push({r,c});
                }
                else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int i=0; i<4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }cnt++;
            }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return fresh == 0 ? cnt: -1 ;
    }
};