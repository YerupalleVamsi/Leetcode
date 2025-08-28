class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>dia;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dia[i-j].push_back(mat[i][j]);
            }
        }
        for (auto& pair : dia) {
    sort(pair.second.rbegin(), pair.second.rend());

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x=dia[i-j].back();
            dia[i-j].pop_back();
            mat[i][j]=x;
        }
    }
    return mat;

    }
};