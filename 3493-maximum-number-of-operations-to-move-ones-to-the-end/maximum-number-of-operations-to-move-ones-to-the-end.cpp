class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ones++;
        }
        bool allones = true;
        int cnt1=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0' && cnt1!=ones){
                allones=false;
                break;
            }
            else if(s[i]=='1'){
                cnt1++;
            }
        }
        if(allones) return 0;
        int cnt2=0;
        int res=0;
        bool taken =false;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='1'){
                taken = true;
                cnt2++;
            }
            if(s[i]=='0' && taken){ 
                res+=cnt2;
                taken = false;}
        }
        return res;
    }
};