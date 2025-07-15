class Solution {
public:
bool isvowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}
    bool isValid(string word) {
        if(word.size()<3)return false;
        bool v=false;
        bool con=false;
        
        
        for(char c:word){
            if(!isalnum(c))return false;
            if(isvowel(c))v=true;
            else if(isalpha(c))con=true;

        }
        return (v && con);
    }
};