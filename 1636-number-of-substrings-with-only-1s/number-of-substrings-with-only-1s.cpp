class Solution {
public:
    const int MOD = 1e9+7;
    int numSub(string s) {
        int curr=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                res=(res+curr)%MOD;
                curr++;
            }
            else {
                res=(res+curr)%MOD;
                curr=0;
            }
        }
         res=(res+curr)%MOD;
         return res;
    }
};