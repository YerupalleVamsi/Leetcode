class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        int min_x=r;
        int min_y=c;
        int max_x=-1;
        int max_y=-1;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                min_x=min(i,min_x);
                min_y=min(j,min_y);
                max_x=max(max_x,i);
                max_y=max(max_y,j);
                 }
            }
        }
        if(max_x==-1)return 0;
        return (max_y - min_y + 1) * (max_x - min_x + 1);
    }
};