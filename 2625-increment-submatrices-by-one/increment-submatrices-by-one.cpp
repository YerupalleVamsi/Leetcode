class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>pre(n,vector<int>(n,0));
        for(auto it:queries){
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];
            pre[r1][c1]+=1;
            if(c2+1<n) pre[r1][c2+1]-=1;
            if(r2+1<n) pre[r2+1][c1]-=1;
            if(r2+1<n && c2+1<n) pre[r2+1][c2+1]+=1;
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                pre[i][j]+=pre[i][j-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                pre[i][j]+=pre[i-1][j];
            }
        }
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[i][j]+=pre[i][j];
            }
        }
        return res;
    }
};