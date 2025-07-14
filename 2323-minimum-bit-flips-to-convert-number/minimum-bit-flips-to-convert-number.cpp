class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long  x=start^goal;
        int cnt=0;
        for(int i=0;i<=31;i++){
            if(x&(1<<i)){
                cnt++;
            }
        }
        return cnt;
    }
};