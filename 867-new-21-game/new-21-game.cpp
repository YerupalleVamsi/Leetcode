class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        int max_Reach=k-1+maxPts; // we can continue game at k-1 and then we can get the maxPts so that is max_Reach 
        if(k==0 || n>=max_Reach) return 1.0; //at max we can reach k-1+maxPts(reachable) so if n>= that(reachable) then we can return 1.0 

        // now we just want the probability of k<=x<=n 
        // we stop the game when we reach k or exceed k
        // we want the probability of having less than or =n points after completing the game
        vector<double>dp(n+1,0.0);
        dp[0]=1.0;
        double windowsum=1.0, res=0.0;
        for(int i=1;i<=n;i++){
            dp[i]= windowsum / maxPts;
            if(i < k){
                windowsum += dp[i];
            }
            else{
                res+=dp[i]; // reached beyond k
            }
            if(i>= maxPts){
                windowsum -=dp[i-maxPts]; 
            }
        }
        return res;

    }
};