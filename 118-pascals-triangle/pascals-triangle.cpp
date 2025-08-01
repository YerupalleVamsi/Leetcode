class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        res.push_back({1}); // start with 1
        if(n==1)return res;
            vector<int>curr;
            for(int i=1;i<n;i++){
                vector<int>prev=res[i-1];
                curr.push_back(prev[0]);
                for(int j=1;j<prev.size();j++){
                    int sum=prev[j-1]+prev[j];
                    curr.push_back(sum);
                }
                curr.push_back(prev.back());
                res.push_back(curr);
                curr.clear();
            }
        
        return res;
    }
};