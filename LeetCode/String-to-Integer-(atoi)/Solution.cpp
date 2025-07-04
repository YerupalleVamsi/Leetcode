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
            i++;
        }
        while(i<n && isdigit(s[i])){
            news.push_back(s[i]);
            i++;
        }
        long long ans=0;
        for(char ch:news){
            ans=ans*10+(ch-'0');
            if(!isnegative && ans>INT_MAX) return INT_MAX;
            if(isnegative && -ans<INT_MIN) return INT_MIN;
        }
        if(isnegative) ans= -ans;
        return (int) ans;
    }
};