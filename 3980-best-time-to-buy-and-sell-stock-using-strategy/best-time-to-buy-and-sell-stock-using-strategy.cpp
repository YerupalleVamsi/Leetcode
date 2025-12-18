class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>prefix(n+1,0);
        vector<long long>ones(n+1,0);
        long long base=0;
        for(int i=0;i<n;i++){
            long long res = 1LL * strategy[i] * prices[i];
            long long o  = 1LL * 1 *prices[i];
            prefix[i+1] = prefix[i] + res;
            ones[i+1] = ones[i] +  o;
            base+=res;
        }
        long long max_profit=base;
        int l=0;
        for(int r=0;r<n;r++){
            if(r-l+1 == k){
                long long curr = base;
                curr-=prefix[r+1] - prefix[l];
                int mid = l+k/2;
                long long X = curr + ones[r+1] - ones[mid];
                max_profit = max({max_profit,X});
                l++;
            }
        }
        return max_profit;
    }
};