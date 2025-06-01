class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> res(r-k+1,vector<int>(c-k+1,0));
        for (int i = 0; i <= r - k; ++i) {
            for (int j = 0; j <= c - k; ++j) {
              int mindiff=INT_MAX;
              vector<int>a;
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        a.push_back(grid[i+x][j+y]);
                    }
                }
               sort(a.begin(),a.end());
               for(int z=1;z<a.size();z++){
                if(a[z]==a[z-1])continue;
                int diff=abs(a[z]-a[z-1]);
                mindiff=min(mindiff,diff);
               }
               res[i][j]=mindiff == INT_MAX? 0:mindiff;
            }
            
        }
        return res;
    }
};
