class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int min=INT_MAX;
        for(int i=0;i<cost.size();i++){
            if(cost[i]<min){
                min=cost[i];
                cost[i]=min;
            }
            else{
                cost[i]=min;
            }
        }
        return cost;
    }
};