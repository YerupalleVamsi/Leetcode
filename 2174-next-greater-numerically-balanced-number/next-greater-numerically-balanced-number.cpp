class Solution {
public:
    bool check(int num){
        string s =  to_string(num);
        vector<int>freq(11,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'0']++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0 && freq[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=9999999999;i++){
            if(check(i)){
                return i;
            }
        }
        return 0;
    }
};