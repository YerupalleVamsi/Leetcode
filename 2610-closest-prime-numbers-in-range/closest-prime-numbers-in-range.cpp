class Solution {
public:
  bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isPrime(i))
            ans.push_back(i);
            
            }
            if(ans.size()<2)return{-1,-1};
int m1,m2;
int diff=INT_MAX;
for(int i=1;i<ans.size();i++)
{
    if(ans[i]-ans[i-1]<diff){
        diff=ans[i]-ans[i-1];
        m1=ans[i];
        m2=ans[i-1];
    }
}

    return{m2,m1} ;    
    }

};