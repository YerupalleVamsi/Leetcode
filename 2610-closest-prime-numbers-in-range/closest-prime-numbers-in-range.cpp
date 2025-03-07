class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isPrime[i])
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