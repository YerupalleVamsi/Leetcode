class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        // for(int i:nums)
        // cout << i <<  " ";
        for(int i:nums){
            mpp[i]++;
        }
        vector<int>counter;
        for(auto it:mpp){
            counter.push_back(it.second);
        }
        sort(counter.begin(),counter.end());
        for (int i = 0; i < counter.size(); i++) {
        if (k >= counter[i]) {
            k -= counter[i];   
            counter[i] = 0;    
        }   else {
            break;
        }
        }

        int res=0;
        for(int i:counter)
        if(i>0)res++;
        return res;}
};