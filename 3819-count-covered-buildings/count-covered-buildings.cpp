class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end());
        unordered_map<int,vector<int>>mx,my;
        for(auto it:buildings){
            mx[it[0]].push_back(it[1]);
            my[it[1]].push_back(it[0]);
        }
        int cnt=0;
        for(auto it:buildings){
            int x = it[0];
            int y = it[1];
            if(mx[x].back()>y && mx[x].front()<y && my[y].back()>x && my[y].front()<x)cnt++;
        }
        return cnt;
    }
};