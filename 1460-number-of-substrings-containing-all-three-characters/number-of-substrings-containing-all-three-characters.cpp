class Solution {
public:
    int numberOfSubstrings(string s) {
        int inabc[3]={0};
        int ans=0;
        int n=s.size();
        int l=0;
        for(int r=0;r<n;r++){
            inabc[s[r]-'a']++;
            while(inabc[0]&&inabc[1]&&inabc[2]){
                ans+=n-r;
                inabc[s[l]-'a']--;
                l++;
            }
        }
       return ans;
    }
};