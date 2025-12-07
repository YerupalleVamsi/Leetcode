class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>f1(26,0),f2(26,0);
        for(auto it:s){
            f1[it-'a']++;
        }
        for(auto it:t)
        f2[it-'a']++;
        for(int i=0;i<26;i++){
            if(f1[i]<f2[i]){
                return i+'a';
            }
        }
        return 'x';
    }
};