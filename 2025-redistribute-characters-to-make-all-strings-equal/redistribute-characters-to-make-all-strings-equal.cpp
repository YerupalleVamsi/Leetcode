class Solution {
public:
    bool makeEqual(vector<string>& words) {
    unordered_set<string>s(words.begin(),words.end());
    if(s.size()==1) return true;
     unordered_map<char,int>mpp;
     for(string s:words){
        for(char c:s){
            mpp[c]++;
        }
     }
     int n=words.size();
    for(auto it:mpp){
        if(it.second % n !=0) return false;
    }
    return true;}
};