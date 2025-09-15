class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cnt=0;
        unordered_set<char>s;
        for(char c:brokenLetters)
        s.insert(c);
        int p=0;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(p==0){
                    cnt++;
                }
                p=0;
            }
            if(s.count(text[i])>0){
                p++;
            }
        }
        if(p==0){
            cnt++;
        }
        return cnt;
    }
};