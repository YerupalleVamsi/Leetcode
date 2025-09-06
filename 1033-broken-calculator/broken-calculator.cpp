class Solution {
public:
    int brokenCalc(int s, int t) {
       long long op=0;
       while(t>s){
        if(t%2==0){
            t/=2;
        }
        else{
            t++;
        }
        op++;
       } 
       return op+(s-t);
    }
};