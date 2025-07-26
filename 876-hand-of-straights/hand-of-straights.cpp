class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int>mpp;
        for(int i:hand){
            mpp[i]++;
        }
        for(auto &[n,cnt]:mpp){
            if(cnt>0){
                for(int i=1;i<k;i++){
                    if(mpp[n+i]<cnt){
                        return false;
                    }
                    mpp[n+i]-=cnt;
                }
            }
        }
        return true;
    }
};