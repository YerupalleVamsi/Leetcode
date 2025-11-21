class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>st(26,-1);
        vector<int>end(26,-1);
        int res=0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(st[c-'a']==-1){
                st[c-'a']=i;
            }
            else{
                end[c-'a']=i;
            }
        }
        for(int i=0;i<26;i++){
            if(end[i]==-1 || st[i]==-1) continue;
            vector<bool>seen(26,false);
            for(int j=st[i]+1;j<end[i];j++){
                seen[s[j]-'a'] = true;
            }
            for(auto it:seen){
                if(it)
                res++;
            }
            }
        return res;
    }
};