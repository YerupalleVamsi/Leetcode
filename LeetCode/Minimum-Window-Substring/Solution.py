class Solution {
public:
    
    bool checkAllPresent(vector<int>& vec1, vector<int>& vec2) {
    for (int i = 0; i < 52; ++i) {
        if (vec2[i] < vec1[i])
            return false;
    }
    return true;
    }

    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";
        vector<int>freq1(52,0);
        vector<int>freq2(52,0);
        for(char c:t){
            if(islower(c))
            freq1[c-'a']++;
            else
            freq1[c-'A'+26]++;
        }
        int windowsize=t.size();
        int minwinsize=INT_MAX;
        int currwinstart=0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(islower(s[r])){
                freq2[s[r]-'a']++;
            }
            else if(isupper(s[r])){
                freq2[s[r]-'A'+26]++;
            }

            while(checkAllPresent(freq1,freq2)){
                if(r-l+1<minwinsize){
                    minwinsize=r-l+1;
                    currwinstart=l;
                }
            
            
            else{
                    if(islower(s[l]))
                        freq2[s[l]-'a']--;
                    else{
                        freq2[s[l]-'A'+26]--;
                    }
                   
                    l++;
            }}
            r++;

        }
         if(minwinsize == INT_MAX) return "";

         return s.substr(currwinstart,minwinsize);
        
        }
    
};