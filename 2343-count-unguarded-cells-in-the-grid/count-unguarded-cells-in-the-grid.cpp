class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        // -1 - wall
        //  0 - not visited or un guarded
        //  1 - guard
        //  2 - GUARDED
        for(auto it:walls){
            grid[it[0]][it[1]] = -1;
        }
        for(auto it:guards){
            grid[it[0]][it[1]] = 1;
        }
        for(int i=0;i<m;i++){
            bool g = false;
            for(int j =0; j<n;j++){
                if(grid[i][j] == 1) g =true;
                else if(grid[i][j] == -1) g = false;
                else if(g) grid[i][j] = 2;
            }
            g =false;
            for(int j = n-1;j>=0;j--){
                if(grid[i][j] == 1) g =true;
                else if(grid[i][j] == -1) g = false;
                else if(g) grid[i][j] = 2;
            }
        }
        for(int j=0;j<n;j++){
            bool g = false;
            for(int i =0; i<m;i++){
                if(grid[i][j]== 1) g =true;
                else if(grid[i][j] == -1) g = false;
                else if(g) grid[i][j] = 2;
            }
            g =false;
            for(int i = m-1;i>=0;i--){
                if(grid[i][j] == 1) g =true;
                else if(grid[i][j] == -1) g = false;
                else if(g) grid[i][j] = 2;
            }
        }
        int ug=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0)
                ug++;
            }
        }
        return ug;
    }
};