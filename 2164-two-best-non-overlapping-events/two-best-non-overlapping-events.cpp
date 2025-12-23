class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int res =  0;
        for(auto it:events) res=max(res,it[2]);
        int curr=0;
        for(auto it:events){
            while(!pq.empty() && pq.top().first < it[0]){
                auto[e,v]  = pq.top();pq.pop();
                curr = max(curr,v);
            }
            res=max(res,curr+it[2]);
            res=max(res,it[2]);
            pq.push({it[1],it[2]});
        }
        return res;
    }
};