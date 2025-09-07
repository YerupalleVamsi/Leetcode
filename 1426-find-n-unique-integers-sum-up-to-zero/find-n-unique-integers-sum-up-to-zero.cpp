class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)return {0};
        vector<int>res;
        for(int i=n/2;i>0;i--){
            res.push_back(i);
            res.push_back(-i);
        }
        if(n&1)res.push_back(0);
        return res;
    }
};