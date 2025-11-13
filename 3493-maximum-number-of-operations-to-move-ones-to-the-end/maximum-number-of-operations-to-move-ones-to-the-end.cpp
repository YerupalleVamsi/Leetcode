class Solution {
public:
    int maxOperations(string s) {
        int cnt=0;
        int res=0;
        bool taken =false;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='1'){
                taken = true;
                cnt++;
            }
            if(s[i]=='0' && taken){ 
                res+=cnt;
                taken = false;}
        }
        return res;
    }
};