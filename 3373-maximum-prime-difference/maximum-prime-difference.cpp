class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
       int n=nums.size();
       int r=0;
       for(int i:nums){
        r=max(i,r);
       }
       vector<bool>prime(r+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=r;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=r;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int>p;
        for(int i=0;i<n;i++){
            if(prime[nums[i]])
            p.push_back(i);
        }
        if(p.size()==1)return 0;
        sort(p.begin(),p.end());
        return abs(p[0]-p[p.size()-1]);


    }
};