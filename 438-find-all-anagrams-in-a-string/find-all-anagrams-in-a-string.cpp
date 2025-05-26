class Solution {
public:
    bool isequal(vector<int>freq1,vector<int>freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        vector<int>res;
        for(char c:p){
            freq1[c-'a']++;
        }
        int l=0;
        int r=0;
        while(r<s.size()){
            freq2[s[r]-'a']++;
            if(r-l+1==p.size()){
                if(isequal(freq1,freq2)){
                res.push_back(l);}
            }
            if(r-l+1<p.size())
                r++;
            else{
                 freq2[s[l]-'a']--;
                 r++;
                 l++;
            }
        }
        return res;
    }
};