class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       string cur(num,'0');
        for(int i=0;i<num;i++){
            if(sum >= 9){
            cur[i] = '9';
            sum-=9;
            }
            else{
                cur[i]=sum+'0';
                sum=0;
                break;
            }
        }
        return sum > 0 ? "" : cur;
    }
};