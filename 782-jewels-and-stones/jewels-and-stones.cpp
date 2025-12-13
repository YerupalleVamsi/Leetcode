class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>s(jewels.begin(),jewels.end());
        int cnt=0;
        for(auto it:stones){
            if(s.count(it))
            cnt++;
        }
        return cnt;
    }
};