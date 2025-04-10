class Solution {
public:
    int myAtoi(string s) {
        vector<char>news;
        int i=0;
        int n=s.size();
        while(i<n&&s[i]==' ')i++;
        bool isnegative=false;
        if(i<n&&(s[i]=='-'||s[i]=='+')){
            isnegative=(s[i]=='-');
