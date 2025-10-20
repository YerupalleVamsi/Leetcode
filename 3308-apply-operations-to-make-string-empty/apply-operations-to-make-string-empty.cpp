class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        int max_freq=0;
        for(auto &it:mpp){
            max_freq=max(max_freq,it.second);
        }
        string res ="";
        for(int i  =s.size()-1;i>=0;i--){
            if(mpp[s[i]]==max_freq){
                res = s[i] + res;
                mpp[s[i]]--;
            }
        }
        return res;
    }
};