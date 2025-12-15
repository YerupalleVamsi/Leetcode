class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res=1;
        long long curr_streak=1;
        for(int i=1;i<prices.size();i++){
                if(prices[i-1]-prices[i]==1){
                    curr_streak++;
                   res+=curr_streak;
                }
                else {curr_streak=1;
                res+=curr_streak;
                } 
        }
        return res;
    }
};