class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        vector<int>f(26,0);
        for(auto it:allowed)f[it-'a']++;
        for(auto it:words){
            bool s = true;
            for(auto x:it){
                if(f[x-'a']==0){
                    s = false;
                }
            }
            if(s)cnt++;
        }
        return cnt;
    }
};