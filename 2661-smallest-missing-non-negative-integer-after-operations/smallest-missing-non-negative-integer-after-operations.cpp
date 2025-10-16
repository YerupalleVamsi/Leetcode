class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            //  int rem = i % value;
            int rem = ((i % value) + value) % value; //for -ves also
            mpp[rem]++;
        }
        for(int i=0;i<=1e5;i++){
            int curr = i % value;
            if(mpp.find(curr)!=mpp.end() && mpp[curr] > 0){
                mpp[curr]--;
            }
            else if(mpp[curr] == 0){
                return i;
            }
        }
        return -1;
    }
};