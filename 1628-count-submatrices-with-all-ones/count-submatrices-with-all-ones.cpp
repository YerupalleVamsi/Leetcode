class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int cnt=0;
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>> heights(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1)
                heights[i][j]=(i>0?heights[i-1][j]:0)+1;
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int min_height=heights[i][j];
                for(int k=j;k>=0;k--){
                    min_height=min(min_height,heights[i][k]);
                    if(min_height==0)break;
                    cnt+=min_height;
                    
                }
            }
        }
        return cnt;
        

    }
};