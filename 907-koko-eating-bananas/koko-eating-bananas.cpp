class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int right = piles[0]; 
    for (int num : piles) {
        if (num > right)
            right = num;
    }
        int k=0;
        int left=1;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long sum=0;
            for(int i=0;i<piles.size();i++){
                sum+=(piles[i]+mid-1)/mid;
            }
            if(sum>h){
                left=mid+1;
            }
            else{
                k=mid;
                right=mid-1;
            }
        }
       return k;
    }
};