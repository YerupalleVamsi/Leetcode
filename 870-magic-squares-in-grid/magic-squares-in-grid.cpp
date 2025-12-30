class Solution {
public:
    bool isvalid(int i,int j,vector<vector<int>>&grid){
        if(i-1<0 || i+1 > grid.size()-1 || j+1 > grid[0].size()-1 || j-1 <0) return false;
    vector<int> seen(10, 0);
    for (int r = i - 1; r <= i + 1; r++) {
        for (int c = j - 1; c <= j + 1; c++) {
            int v = grid[r][c];
            if (v < 1 || v > 9 || seen[v]) return false;
            seen[v] = 1;
        }
    }
        int s1 = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];
        int s2 = grid[i][j-1]   + grid[i][j]   + grid[i][j+1];
        int s3 = grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
        int s4 = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];
        int s5 = grid[i-1][j]   + grid[i][j]   + grid[i+1][j];
        int s6 = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];
        int s7 = grid[i-1][j-1] + grid[i][j]   + grid[i+1][j+1];
        int s8 = grid[i-1][j+1] + grid[i][j]   + grid[i+1][j-1];
       return s1 == 15 && s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6 && s6 == s7 && s7 == s8;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==5 && isvalid(i,j,grid)) cnt++;
            }
        }
        return cnt;
    }
};