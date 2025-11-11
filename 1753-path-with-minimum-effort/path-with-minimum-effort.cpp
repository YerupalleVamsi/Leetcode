class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int R = heights.size();
        int C = heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>dp(R,vector<int>(C,INT_MAX));
        pq.push({0,0,0});
        dp[0][0]=0;
        int dirs[4][2] = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        while(!pq.empty()){
            auto[dis,r,c] = pq.top();pq.pop();
            if(r == R-1 && c==C-1) return dis;
            if(dis > dp[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr = r+dirs[i][0];
                int nc = c+dirs[i][1];
                if(nr<0 || nc<0 || nr>=R || nc>=C) continue;
                int next = max(dis,abs(heights[r][c] - heights[nr][nc]));
                if(next<dp[nr][nc]){
                    dp[nr][nc] = next;
                pq.push({next,nr,nc});}
            }
        }
        return 0;}
};