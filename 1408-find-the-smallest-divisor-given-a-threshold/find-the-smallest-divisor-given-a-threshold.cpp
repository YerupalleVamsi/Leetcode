class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=-1;
        for(int x:nums)
        {           if(x>high){
                high=x;}
        }
        int mindiv=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long sum=0;
            for(int num:nums){
                sum+=(num+mid-1)/mid;
            }
            if(sum>threshold){
                low=mid+1;
            }
            else{
                mindiv=mid;
                high=mid-1;
            }     
        }
         return mindiv;
}
    
};