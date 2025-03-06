class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long N=grid.size();
        long n=N*N;
        long s_e=n*(n+1)/2;
        long ss_e=(n*(n+1)*(2*n+1))/6;
        long s_g=0;
        long ss_g=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                s_g+=grid[i][j];
                ss_g+=grid[i][j]*grid[i][j];
            }
        }
        long x=s_g-s_e;
        long y=ss_g-ss_e;
       int b=((y/x)-x)/2;
        int a= b+x;
        
        return {a,b};
    }
};