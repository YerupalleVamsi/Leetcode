class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,1});
        vector<vector<int>> dp(n,vector<int>(m, INT_MAX));
        dp[0][0]=1;
        int dirs[8][2] = {
            {1,0},
            {-1,1},
            {1,-1},
            {0,1},
            {0,-1},
            {1,1},
            {-1,-1},
            {-1,0}
        };
        while(!pq.empty()){
            auto [x,y,dis] = pq.top();
            pq.pop();
            if(dis > dp[x][y]) continue;
            if(x == n-1 && y==m-1) return dis;
            for(int i=0;i<8;i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx <0 || nx >=n || ny<0 || ny>=m || grid[nx][ny]==1) continue;
                if(dis + 1 < dp[nx][ny]){
                    dp[nx][ny] = dis+1;
                    pq.push({nx,ny,dis+1});
                }
            }
        }
        return -1;
    }
};