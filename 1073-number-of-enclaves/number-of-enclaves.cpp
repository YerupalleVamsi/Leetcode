class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j){
        int R =  grid.size();
        int C = grid[0].size();
        if(i < 0 || j < 0 ||  j>=C || i>=R || grid[i][j] == 0 ) return;
        grid[i][j] = 0;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int R =  grid.size();
        int C = grid[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if((i==0 || j==0 || j==C-1 || i == R-1) && grid[i][j] == 1){
                    dfs(grid,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};