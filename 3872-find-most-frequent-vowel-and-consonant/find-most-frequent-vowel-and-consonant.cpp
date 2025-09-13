class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>f(26,0);
        for(char c:s)
        f[c-'a']++;
        int v=0;
        int con=0;
        string vows="aeiou";
        for(char c:vows){
        v=max(v,f[c-'a']);
        }
        cout << v <<" ";
        for(char c:s){
            if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
            con=max(con,f[c-'a']);
        }
        cout << con ;
        return v+con;
    }
};