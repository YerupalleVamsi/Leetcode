class Solution {
public:
    int totalMoney(int n) {
        int curr = 1;
        int prev  = 1;
        int res=0;
        for(int i=1;i<=n;i++){
            if(i % 7 == 1 && i>7){
                curr = prev+1;
                prev= curr;
            }
            res+=curr;
            curr++;
        }
        return res;
    }
};