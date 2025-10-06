class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq; //[time,X,Y]

        vector<vector<bool>> vis(R, vector<bool>(C, false));
        int dirs[4][2] = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
            };
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while(!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();

            if(x == R-1 && y == C-1)
                return t;

            for(auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= R || ny >= C || vis[nx][ny])
                    continue;
                vis[nx][ny] = true;
                int nt = max(t, grid[nx][ny]);
                pq.push({nt, nx, ny});
            }
        }
        return -1; 
    }
};
