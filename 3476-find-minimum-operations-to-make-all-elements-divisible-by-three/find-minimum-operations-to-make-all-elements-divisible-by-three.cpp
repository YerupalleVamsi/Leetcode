class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;
        for(auto it:nums){
        int r= it%3;
        if(r==1) op++;
        else if(r==2) op++;    
        }
        return op;
    }
};