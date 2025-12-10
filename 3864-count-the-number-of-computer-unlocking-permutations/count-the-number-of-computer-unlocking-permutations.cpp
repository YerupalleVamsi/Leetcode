class Solution {
public:
    const int MOD = 1e9+7;
   long long fac(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }
    int countPermutations(vector<int>& complexity) {
    int first = complexity[0];
    sort(complexity.begin(),complexity.end());
    int cnt=0;
    for(int i=0;i<complexity.size();i++){
        if(complexity[i]==first) cnt++;
        if(cnt>1) return 0;
    }
    if(first!=complexity[0]) return 0;
    int n = complexity.size();
     long long res = fac(n-1);
     return res%MOD;   
    }
};