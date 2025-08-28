class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int>>dia;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dia[i-j].push_back(mat[i][j]);
            }
        }
    //     for (const auto& pair : dia) {
    //     std::cout << "Key: " << pair.first << ", Vector: ";
    //     for (int val : pair.second) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }
        for (auto& pair : dia) {
            if(pair.first>=0)
    sort(pair.second.begin(), pair.second.end());
    else
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