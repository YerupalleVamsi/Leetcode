class Solution {
public:
    int mySqrt(int x) {
       int low=1;
       int high=x;
       long long res=0;
       while(low<=high){
        int mid=low+(high-low)/2;
       
        if(x/mid==mid){
            return mid;
        }
        else if(x/mid<mid){
            high=mid-1;
        }
        else{
            low=mid+1;
            res=mid;
        }
       } 
       return res;
    }
};
    