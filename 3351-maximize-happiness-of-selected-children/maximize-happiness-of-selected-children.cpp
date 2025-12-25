class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long cnt=0;
        long long res = 0;
        sort(happiness.rbegin(),happiness.rend());
        for(int i=0;i<k;i++){
            long long happy = max(0LL,happiness[i] - cnt);
            res+=happy;
            cnt++;
        }
        return res;
    }
};