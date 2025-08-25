class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mpp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int>result;
        for (auto &p : mpp) {
        int key = p.first;
        auto &vec = p.second;

        if (key % 2 == 1) {
            result.insert(result.end(), vec.begin(), vec.end());
        } else {
            result.insert(result.end(), vec.rbegin(), vec.rend());
        }
    }

        return result;
    }
};