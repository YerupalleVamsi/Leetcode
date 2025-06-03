class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        for(char ch:text){
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n')
            mpp[ch]++;
        }
        mpp['l']/=2;
        mpp['o']/=2;
        int mini=INT_MAX;
        string balloon = "balon";
        for(char ch:balloon){
            mini=min(mini,mpp[ch]);
        }
        return mini;
    }
};