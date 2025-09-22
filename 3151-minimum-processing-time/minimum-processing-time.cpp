class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n=processorTime.size();
        sort(tasks.begin(),tasks.end());
        sort(processorTime.rbegin(),processorTime.rend());
        int res=0;
        for(int i=0;i<n;i++){
        res=max(res,processorTime[i]+tasks[4*i+3]);
        }
        return res;

    }
};