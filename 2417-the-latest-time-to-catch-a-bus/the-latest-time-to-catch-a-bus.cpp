class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        // we have to get as late as possible
        int time=0;
        int j=0;
        unordered_map<int,int>seen;
        for(int i=0;i<buses.size();i++){
            int cnt=0;
            while(j<passengers.size() && cnt<capacity && passengers[j]<=buses[i]){
                if( seen.find(passengers[j]-1)== seen.end())
                {
                    time=passengers[j]-1;
                }
                seen[passengers[j]]++;
                j++;
                cnt++;
            }
            if(cnt<capacity && seen.find(buses[i])==seen.end()) time = buses[i];

        }
        return time;}

};