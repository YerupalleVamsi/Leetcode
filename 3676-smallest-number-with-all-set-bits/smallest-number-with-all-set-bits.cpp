class Solution {
public:
    int smallestNumber(int n) {
        int i=1;
        while(1){
            int num = pow(2,i)-1;
            if(num >= n){
                return num;
            }
            i++;
        }
        return 0;
    }
};