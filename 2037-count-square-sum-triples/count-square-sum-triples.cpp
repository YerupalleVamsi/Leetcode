class Solution {
public:
    long long rt(int x){
      int l=1;
      int h=x;
      while(l<=h){
        long long mid= l+(h-l)/2;
        long long sq = 1LL * mid * mid;
        if(sq==x){
            return mid;
        }
        else if(sq<x){
            l=mid+1;
        }
        else h=mid-1;
      }  
      return INT_MAX;
    }
    int countTriples(int n) {
        int cnt=0;
        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                if(rt(a*a+b*b)<=n){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};