class Solution {
public:
    int howmanyexist(long long a,long long b,long long n){
        int gap=0;
        while(a<=n){
            gap+=min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }

    int findKthNumber(int n, int k) {
       int curr=1;
       k--;
       while(k>0){
        int count=howmanyexist(curr,curr+1,n);
        if(count<=k){
            curr++;
            k-=count;
        }
        else{
            curr*=10;
            k--;
        }
       
       }
       return curr;}
};
