class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int min_cost=0;
        int l=0;
        for(int r=1;r<s.size();r++){
            if(s[r]==s[l]){
                if(neededTime[l] < neededTime[r])
                {
                    min_cost += neededTime[l];
                    l=r;
                }
                else
                min_cost+=neededTime[r];
            }
            else
            l=r;
        }
        return min_cost;
    }
};