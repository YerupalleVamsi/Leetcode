class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        unordered_map<char,int>mpp;
        for(auto it:allowed) mpp[it]++;
        for(auto it:words){
            unordered_map<char,int>mp;
            for(auto c:it){
                mp[c]++;
            }
            bool s = true;
            for(auto [k,v]:mp){
                if(!mpp.count(k)){
                    s = false;
                }
            }
            if(s)cnt++;
        }
        return cnt;
    }
};