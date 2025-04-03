class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>&visited,vector<vector<char>>&grid){
        visited[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == '1'){
                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                
            }

        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1' && !visited[r][c]){
                    cnt++;
                    bfs(r,c,visited,grid);
                }
            }
        }
        return cnt;
    }
};