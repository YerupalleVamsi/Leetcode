class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& c, int rem) {
    priority_queue<pair<double, pair<int, int>>> pq;
        for(auto i:c){
            int pass=i[0];
            int total=i[1];
            double curr=(double)pass/total;
            double diff=((double)(pass+1)/(total+1))-curr;
            pq.push({diff,{pass,total}});
        }
        while(rem>0){
            int pass=pq.top().second.first+1;
            int total=pq.top().second.second+1;
            pq.pop();
            rem--;
            double curr=(double)pass/total;
            double diff=((double)(pass+1)/(total+1))-curr;
            pq.push({diff,{pass,total}});
        }
        double total_ratio=0.0;
        while(!pq.empty()){
            double ratio=(double)pq.top().second.first/pq.top().second.second;
            pq.pop();
            total_ratio+=ratio;
        }
        return total_ratio/c.size();
    }
};