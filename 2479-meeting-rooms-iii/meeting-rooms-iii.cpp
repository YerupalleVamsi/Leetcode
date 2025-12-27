class Solution {
public:
    typedef long long ll;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<ll>freq(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq2;
        for(int i=0;i<n;i++){
            pq1.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            while(!pq2.empty()&& pq2.top().first<=meetings[i][0]){
                auto [endtine , room_number] =  pq2.top();pq2.pop();
                pq1.push(room_number);
            }
            if(!pq1.empty()){
                ll room_number = pq1.top();pq1.pop();
                pq2.push({meetings[i][1],room_number});
                freq[room_number]++;
            }
            else{
                auto [end_time, room_number] = pq2.top();pq2.pop();
                pq2.push({end_time + meetings[i][1]-meetings[i][0],room_number});
                freq[room_number]++;
            }
        }
        ll r_no = -1;
        ll f = INT_MIN;
        for(int i=0;i<n;i++){
            if(freq[i]>f){
                r_no=i;
                f = freq[i];
            }
        }
        return r_no;

    }
};