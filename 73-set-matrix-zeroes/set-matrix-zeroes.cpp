class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr=false;
        bool fc=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
            fc=true;
            break;
        }}
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
            fr=true;
            break;
        }}
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++){
                    if(matrix[i][j]==0){
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
            }
        }
        for(int i=1;i<matrix.size();i++)
        {
            if(matrix[i][0]==0){
                fill(matrix[i].begin(),matrix[i].end(),0);
            }
        }
        for(int j=1;j<matrix[0].size();j++)
        {
            if(matrix[0][j]==0){
               for(int i=0;i<matrix.size();i++){
                matrix[i][j]=0;
               }
            }
        }
        if(fr){
           fill(matrix[0].begin(),matrix[0].end(),0);
        }
        if(fc){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }

        }
        
    }
};