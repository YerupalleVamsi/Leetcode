class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int start=0;
        int i=0;
        string ans;
        while(start<n){
            while(i<n && s[i]==' ')i++;
            start=i;
            while(i<n && s[i]!=' ')i++;
            if(start<i){
            if(ans.empty())ans=s.substr(start,i-start);
            else{
                ans=s.substr(start,i-start)+' '+ans;
            }}
        }
        return ans;

    }
};