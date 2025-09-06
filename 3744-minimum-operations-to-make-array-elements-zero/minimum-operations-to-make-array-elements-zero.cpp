class Solution {
public:
    long long help(int n){ // gives ops from 1 to n
        long long res=0;
        long long mul=1; // bucket 
        int cur = 1;
        while(cur <= n ){
            long long next = min(cur*4, n+1);
            long long cnt = next - cur;
            res+= (cnt*mul);
            mul++;
            cur=next;
        }
        return res;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long ops = 0;
        for (auto &it : queries) {
            long long l = it[0];
            long long r = it[1];
            long long res= help(r)-help(l-1); // gives for ops from l to r inclusive man
            ops+=(res+1)/2; // using instead of ceil
        }
        return ops;
    }
    // O(q*log4(n)) need to find a better sol using bit manipulation nigga
};