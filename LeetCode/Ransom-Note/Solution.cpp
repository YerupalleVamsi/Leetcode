class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>note(26,0);
        vector<int>mag(26,0);
        for(char ch:ransomNote){
            note[ch-'a']++;
        }
        for(char ch:magazine){
            mag[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(note[i]>mag[i])
            return false;
        }
        return true;
    }
};