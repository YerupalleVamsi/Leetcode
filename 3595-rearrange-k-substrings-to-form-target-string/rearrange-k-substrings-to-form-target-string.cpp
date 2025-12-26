class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string,int>mpp;
        if(n%k!=0) return false;
        int split = n/k;
        for(int i=0;i<n;i+=split){
            mpp[s.substr(i,split)]++;
        }

        for(int i=0;i<n;i+=split){
            string x = t.substr(i,split);
            if(mpp.count(x)){
                mpp[x]--;
                if(mpp[x]==0) mpp.erase(x);
            }
            else return false;
        }
        return true;
    }
};