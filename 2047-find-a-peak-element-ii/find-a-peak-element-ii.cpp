class Solution {
public:
    int getmax(vector<vector<int>>&mat,int c){
        int R = mat.size();
        int C = mat[0].size();
        int idx = 0;
        int curr = mat[0][c];
        for(int i=0;i<R;i++){
            if(curr < mat[i][c]){
                idx = i;
                curr = mat[i][c]; 
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
     int R = mat.size();
     int C = mat[0].size();
     int l = 0;
     int h = C-1;
     while(l<=h){
        int mid = l + (h - l)/2;
        int maxi = getmax(mat,mid);
        int left =  mid-1>=0? mat[maxi][mid-1] : -1; 
        int right = mid + 1 <=C-1? mat[maxi][mid+1] : -1;
        if(left< mat[maxi][mid] && mat[maxi][mid] > right){
            return {maxi,mid};
        }
        else if(left > mat[maxi][mid]){
            h = mid-1;; 
        }
        else l = mid+1;
     }
     return {l,h};
    }  
};