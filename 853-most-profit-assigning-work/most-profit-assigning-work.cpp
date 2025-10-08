class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<pair<int,int>>p; // {diff,prof}
        for(int i=0;i<n;i++)
        p.push_back({difficulty[i],profit[i]});
        sort(p.begin(),p.end());
        // for(auto it:p)
        // cout << it.first << " "<< it.second << endl;

        sort(worker.begin(),worker.end());
        int max_profit = 0;
        for(int i = 1; i < n; i++)
            p[i].second = max(p[i].second, p[i-1].second);
        for(int i=0;i<m;i++){
            int energy = worker[i];
            int curr_profit = INT_MIN;
            int low = 0;
            int high = n-1;
            while(low <= high){
                int mid  = low + (high - low)/2;
                if(p[mid].first <= energy){
                    low =  mid+1;
                    curr_profit = max(curr_profit,p[mid].second);
                    }
                else{
                    high = mid-1;
                }
            }
            if(curr_profit != INT_MIN)
            max_profit+=curr_profit;
        }
        return max_profit;
    }
};