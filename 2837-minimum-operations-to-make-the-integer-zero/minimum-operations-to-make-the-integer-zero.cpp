class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
           long long x=num1-1LL*num2*i;  // sum_of_two_powers 
            long long ones=__builtin_popcountll(x);
            if(x < 0) break;
            if(x>=i && ones<=i) return i;  // we need atleast i  2^0's && set bits must be less than or equal to i to make the number we need ones number of set bits and i should be equal or greater than to it
        }
        return -1;
    }
};