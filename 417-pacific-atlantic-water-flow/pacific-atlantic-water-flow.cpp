class Solution {
public:
    set<pair<int,int>> bfs(vector<pair<int,int>> points, vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();
        deque<pair<int,int>> dq;
        set<pair<int,int>> vis;
        for (auto &[x, y] : points) {
            vis.insert({x, y});
            dq.push_back({x, y});
        }

        int dirs[4][2] = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
            };

        while (!dq.empty()) {
            auto [X, Y] = dq.front();
            dq.pop_front(); 
            for (int i = 0; i < 4; i++) {
                int dx = dirs[i][0];
                int dy = dirs[i][1];
                int nx = X + dx;
                int ny = Y + dy;

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && vis.count({nx, ny}) == 0 && heights[nx][ny] >= heights[X][Y]) {  
                    vis.insert({nx, ny});
                    dq.push_back({nx, ny});
                }
            }
        }
        return vis;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();

        vector<pair<int,int>> pacific, atlantic;

        for (int i = 0; i < R; i++) {
            pacific.push_back({i, 0});
            atlantic.push_back({i, C-1});
        }
        for (int j = 0; j < C; j++) {
            pacific.push_back({0, j});
            atlantic.push_back({R-1, j});
        }
        set<pair<int,int>> p = bfs(pacific, heights);
        set<pair<int,int>> a = bfs(atlantic, heights);
        set<pair<int,int>> P_A;
        set_intersection(p.begin(), p.end(), a.begin(), a.end(),
                         inserter(P_A, P_A.begin()));
        vector<vector<int>> res;
        for (auto &p : P_A) {
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
