class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mpp;
        int len = words.size();
        int cnt=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            mpp[c].push_back(i);
        }
        for(auto word : words){
            if(isvalid(word,mpp)){
                cnt++;
            }
        }
        return cnt;
    }
    bool isvalid(string &word,unordered_map<char,vector<int>> &mpp){
        int prev = -1;
        for(char c:word){
            if(mpp.count(c)){
            int CurrentIndex = findIndex(mpp[c],prev);
            if(CurrentIndex==-1) return false;
            else{
                prev = CurrentIndex;
            }}
            else return false;
        }
        return true;
    }
    int findIndex(vector<int> &f,int prev){
        auto it = upper_bound(f.begin(),f.end(),prev);
        return it==f.end()? -1 : *it;
    }
};