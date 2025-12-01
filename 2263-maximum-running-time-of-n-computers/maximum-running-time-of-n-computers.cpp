class Solution {
public:
    bool valid(long long mid,vector<int>&batteries,int n){
        long long sum = 0;
        for(auto it:batteries){
            sum+= min(mid,(long long)it);
            if(sum >= 1LL*mid*n) return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int N = batteries.size();
        long long sum = accumulate(batteries.begin(),batteries.end(),0LL);
        sort(batteries.begin(),batteries.end());
        long long low = 0;
        long long high = sum/n;
        long long best=0;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(valid(mid,batteries,n)){
                best=mid;
                low=mid+1;
            } 
            else high=mid-1;
        }
        return best;
    }
};