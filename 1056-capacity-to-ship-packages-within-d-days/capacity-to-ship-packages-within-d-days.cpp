class Solution {
public:
    bool isvalid(vector<int>&weights,int days,int mincap){
        long long ndays=1,wts=0;
        for(int w:weights){
           
            if(wts+w>mincap){
                wts=w;
                ndays++;
            }
            else
             wts+=w;
            if(ndays>days)
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(), weights.end());  
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            long long mid=low+(high-low)/2;
            if(isvalid(weights,days,mid)){
                high=mid;
            }
            else
            low=mid+1;
        }
        return low;

    }
};