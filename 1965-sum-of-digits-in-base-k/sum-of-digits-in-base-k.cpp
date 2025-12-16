class Solution {
public:
    int sumBase(int n, int k) {
        string res="";
        while(n>0){
            int d = n%k;
            n/=k;
            res = char(d+'0') + res;
           
        }
        int num = stoi(res);
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};