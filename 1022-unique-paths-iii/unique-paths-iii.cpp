class Solution {
public:
    int paths=0;
    int zeros=0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,0));
        int start,end;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    start=i;
                    end=j;
                }
                if(grid[i][j]==0){
                    zeros++;
                }
            }
        }
        dfs(grid,vis,start,end,0);
        return paths;
    }
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int cnt){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==-1 || vis[i][j])return;
        if(grid[i][j]==2){
            if(zeros+1==cnt){
            paths++;}
            return;
            }
        vis[i][j]=true;
         dfs(grid,vis,i+1,j,cnt+1);
        dfs(grid,vis, i-1, j,cnt+1);
        dfs(grid,vis, i, j+1,cnt+1);
        dfs(grid,vis, i, j-1,cnt+1);

    vis[i][j]=false;

    }
};