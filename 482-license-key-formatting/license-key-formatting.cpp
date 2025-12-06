class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='-')continue;
            if(res.size()%(k+1)==k) res+='-';
            res+=toupper(s[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};