class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        unordered_map<char,int>mpp;
        for(auto it:allowed) mpp[it]++;
        for(auto it:words){
            bool s = true;
            for(auto x:it){
                if(!mpp.count(x)){
                    s = false;
                }
            }
            if(s)cnt++;
        }
        return cnt;
    }
};