class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int zero1=0;
        int zero2=0;
        for(int i: nums1){
            if(i==0){
                zero1++;
                sum1+=1;
            }
            else{
                sum1+=i;
            }
        }
        for(int i:nums2){
            if(i==0){
                zero2++;
                sum2+=1;
            }
            else{
                sum2+=i;
            }
        }
        if(zero1==0 && zero2==0 && sum1!=sum2) return -1;
        if((zero1==0 && zero2!=0 && sum1<sum2)|| (zero1!=0 && zero2==0 && sum2<sum1))
        return -1;
        return max(sum1,sum2);

    }
};