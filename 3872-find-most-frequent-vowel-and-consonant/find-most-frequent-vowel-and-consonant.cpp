class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>f(26,0);
        for(char c:s)
        f[c-'a']++;
        int v=0;
        int con=0;
        for(char c:s){
            if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
            con=max(con,f[c-'a']);
            else
            v=max(v,f[c-'a']);
        }
        return v+con;
    }
};