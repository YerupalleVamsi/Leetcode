class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        if(s.size()<3)return s;
        string res="";
        res+=s[0];
        for(int i=1;i<s.size();i++){
           
            if(s[i-1]==s[i]){
                cnt++;
            }
            else
            cnt=1;
            if (cnt<3){
                res+=s[i];
            }
        }
        return res;
    }
};