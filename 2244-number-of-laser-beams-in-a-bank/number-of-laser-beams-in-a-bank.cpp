class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res  = 0;
        vector<int>cnt;
        for(int i=0;i<bank.size();i++){
            int curr = 0;
            string s = bank[i];
            for(char c:s){
                if(c=='1') curr++;
            }
            if(curr!=0)
            cnt.push_back(curr);
        }
        // for(int i:cnt)
        // cout << i << " ";
        for(int i=1;i<cnt.size();i++)
        res+=cnt[i-1]*cnt[i];
        return res;
    }
};