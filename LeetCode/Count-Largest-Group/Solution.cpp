class Solution {
public:
    int countLargestGroup(int n) {
       unordered_map<int,int>map;
       for(int i=1;i<=n;i++){
        int sum=0;
        int t=i;
        while(t>0){
            sum+=t%10;
            t/=10;
        }
        map[sum]++;
       }
       int maxValue=0,cnt=0;
       for (const auto& pair : map) {
        if (pair.second > maxValue) {
            maxValue = pair.second;
            cnt=1;
        }
        else if(pair.second==maxValue){
            cnt++;
        }
    }
    return cnt;
    }
};