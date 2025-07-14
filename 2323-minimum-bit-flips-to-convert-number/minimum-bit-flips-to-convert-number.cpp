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
}; // to count set bits we can use:
   // 1)  __builtin_popcount(n) in cpp only
   // 2) use a while loop: while(n!=0){n=n&(n-1); cnt++;}
   // 3) use a left shift x&(1<<i) in a loop like used in the code
   // 4) while(ans>0){
   //        if(ans&1)cnt++;
   //         ans=ans>>1;
   //     } or like this using right shift
    