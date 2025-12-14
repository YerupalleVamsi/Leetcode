class Solution {
public:
const int MOD = 1e9+7;
    int numberOfWays(string corridor) {
        int seats=0;
        int prev_seat=0;
        int res=1;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                seats++;
                if(seats>2 && seats%2==1){
                    res = (1LL* res * (i-prev_seat)) %MOD;
                }
                prev_seat=i;
            }
        }
        return seats>1 && seats%2==0? res:0;
    }
};