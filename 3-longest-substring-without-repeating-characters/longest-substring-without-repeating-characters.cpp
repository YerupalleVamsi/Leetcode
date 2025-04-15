class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        if(s.size()==0)return 0;
        int maxsize=1;
        int left=0;
        for(int i=0;i<s.size();i++){
            while(seen.count(s[i])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            maxsize=max(maxsize,i-left+1);            
        }
        return maxsize;
    }
};