class Solution {
public:
    int countOdds(int low, int high) {
        int range = (high-low+1);
        return range%2==0? range/2 : (low&1 || high&1)? range/2+1 : range/2;
    }
};