class Solution {
public:
    vector<vector<int>> DIRS = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int max_len=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int curr_len=1+dfs(grid,i,j,k,1,2);
                        max_len=max(curr_len,max_len);
                    }
                }
            }
        }
        return max_len;
    }
    int dfs(vector<vector<int>>&grid,int i,int j,int k,bool turn,int tar){
        int n=grid.size();
        int m=grid[0].size();
        int ni=i+DIRS[k][0];
        int nj=j+DIRS[k][1];
        if(ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj]!=tar){
            return 0;
        }
        int not_take = 1 +dfs(grid,ni,nj,k,turn,2-tar);
        int take=0;
        if(turn){
            take=1+dfs(grid,ni,nj,(k+1)%4,!turn,2-tar);
        }
        return max(take,not_take);

    }
};