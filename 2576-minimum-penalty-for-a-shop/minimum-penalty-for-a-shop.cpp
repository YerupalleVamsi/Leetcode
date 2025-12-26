class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>pref(n+1,0);
        vector<int>suff(n+1,0);
        int res=INT_MAX;
        int idx=0;
        for(int i=0;i<n;i++){
            pref[i+1] = (customers[i] == 'N')? pref[i] + 1 : pref[i];
        }
        for(int i=n-1;i>=0;i--){
            suff[i] = (customers[i] == 'Y')? suff[i+1]+1 : suff[i+1];
        }
        for(int i=0;i<=n;i++){
            int l =  pref[i];
            int r =  suff[i];
            if(res>l+r){
                res=l+r;
                idx=i;
            }
        }
        return idx;
    }
};