class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int min1=nums1[0],min2=nums2[0];
        unordered_set<int>s(nums1.begin(),nums1.end());
        int res;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]<min1)
            min1=nums1[i];
        }
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]<min2){
                min2=nums2[j];
            }
        }
        for(int num:nums2){
            if(s.erase(num))
            res=min(res,num);
        }
        
       
        if(min1==min2 ){
            if(min1<=res)
            return min1;
            else
            return res;}
         else if(min1>min2){
            if(min2*10+min1<=res)
            return min2*10+min1;
            else
            return res;};
       
        if(min1*10+min2<=res)
        return min1*10+min2;
        else
        return res;

    }
};