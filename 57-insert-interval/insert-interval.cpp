class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // let us insert it first into the res 
        intervals.push_back(newInterval);
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        vector<int>prev=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=prev[1]){
                prev[1]=max(prev[1],intervals[i][1]);
            }
            else{
                res.push_back(prev);
                prev=intervals[i];
            }
        }
        res.push_back(prev);
        return res;
    }
};