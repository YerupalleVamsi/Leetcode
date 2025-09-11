class Solution {
public:
    int tar;
    int rec(int curr,int cpy){
        if(curr==tar){
            return 0;
        }
        if(curr>tar) return 1000000;
        int c = 2+rec(curr+curr,curr);
        int p = 1+rec(curr+cpy,cpy);
        return min(c,p);
    }
    int minSteps(int n) {
        tar=n;
        if(n==1) return 0;
        return 1 + rec(1,1);
    }
};