class Solution {
public:
    int maxBottlesDrunk(int full, int cost) {
        int max_drunk=full;
        int empty=full;
        full=0;
        while(empty>=cost){
            empty-=cost;
            full++;
            cost++;
            empty+=full;
            max_drunk+=full;
            full=0;
        }
        return max_drunk;
    }
};