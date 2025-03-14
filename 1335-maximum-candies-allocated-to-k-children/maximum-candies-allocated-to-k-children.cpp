class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
         int high = candies[0]; 
    for (int num : candies) {
        if (num > high)
            high = num;
    }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long sum=0;
            for(int candy:candies){
                sum+=candy/mid;
            }
            if(sum>=k){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
                
            }
        }return ans;
    }
};