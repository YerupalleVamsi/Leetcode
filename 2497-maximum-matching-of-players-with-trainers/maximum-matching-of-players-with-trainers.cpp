class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0; // at max we can get len of players
        int j=0;
        for(int i=0;i<players.size() && j<trainers.size();){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
                
            }
            j++;
        }
        return cnt;
    }
};