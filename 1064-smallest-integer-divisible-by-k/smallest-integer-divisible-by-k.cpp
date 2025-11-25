class Solution {
public:
    int smallestRepunitDivByK(int k) {
      if(k%2==0 || k%5==0) return -1;
      int st = 1;
      int d = 1;
      while(1)
      {
        int rem = st%k;
        if(rem == 0){
            return d;
        }
        st = (st*10 + 1) % k;
        d++;
      }
      return 0; 
    }
};