class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(auto it:word){
            if('A'<=it && 'Z'>=it)cnt++;
        }
        return cnt==0? true: cnt==1? (word[0]>='A'&&word[0]<='Z')?true:false : cnt==word.size()? true:false;
    }
};