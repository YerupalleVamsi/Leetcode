class Solution {
public:
    int numWaterBottles(int full, int cost) {
        int drink=full;
        int empty=full;
        while(empty>=cost){
            int get = empty/cost;
            int rem = empty%cost;
            drink+=get;
            empty=get+rem;
        }
        return drink;
    }
};