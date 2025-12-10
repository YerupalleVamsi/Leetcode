class Solution {
public:
    const int MOD = 1e9+7;
    int countPermutations(vector<int>& complexity) {
    long long res=1;
    int n=complexity.size();
    for(int i=1;i<n;i++){
        if(complexity[i]<=complexity[0]) return 0;
        res*=i;
        res=res%MOD;
    }
    return res;
    }
};