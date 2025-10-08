class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n =  spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>res;
        for(int i=0;i<n;i++){
            int idx = m;
            int low = 0;
            int high = m-1;
            while(low<= high){
                long long mid = low+(high-low)/2;
                long long x = 1LL*spells[i] * potions[mid];
                if(x >= success){
                    idx = mid;
                    high=mid-1;
                }
            else{
                    low =  mid+1;
                }
            }
            res.push_back(m - idx);
        }
        return res;
    }
};