class Solution {
public:
    int numberOfSubstrings(string s) {
        int type=0;
        map<char,int>inabc;
        int ans=0;
        int n=s.size();
        int r=0,l=0;
         while(r<n){
                inabc[s[r]]++;
            while(inabc.size()==3){
                ans+= n-r;
                    if(--inabc[s[l]]==0){
                        inabc.erase(s[l]);
                    }
                l++;    
            }
            r++;
        }return ans;
    }
};