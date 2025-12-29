class Solution {
public:
typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0 && need2==0) return 0;
        ll ans = LLONG_MAX;
        ll res1 = 1LL * costBoth *(need1+need2);
        ll res2 = (1LL * cost1 * need1 ) + (1LL * cost2 * need2);
        ans = min(res1,res2);
        ll res3 = LLONG_MAX;

        ll x = need1 , y = need2;
        ll res4 = max(need1,need2) * 1LL * costBoth;
        ans =  min(ans,res4);
        if(x>y){
            res3 = 1LL * costBoth * y;
            x-=y;
            res3+= x*cost1;
            ans=min(ans,res3);
        }
        else{
            res3 = 1LL * costBoth * x;
            y-=x;
            res3+= y*cost2;
            ans=min(ans,res3);
        }
        return ans;
    }
};