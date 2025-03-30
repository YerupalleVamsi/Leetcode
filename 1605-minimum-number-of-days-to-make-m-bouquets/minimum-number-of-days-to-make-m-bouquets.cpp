class Solution {
public:
    bool check(vector<int>& bloomDay,int m,int k,int currday){
        int count=0,boq=0;
        for(int bloom: bloomDay){
            if(bloom<=currday){
                count++;
                if(count==k){
                    boq++;
                    count=0;
                }}
            else{
                count=0;
            }
            if(boq>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())return -1;
        int high=bloomDay[0];
        for(int num:bloomDay){
            if(num>high)
            high=num;
        }
        int low=bloomDay[0];
        for(int num:bloomDay){
            if(num<low)
            low=num;
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return low;
    }
};