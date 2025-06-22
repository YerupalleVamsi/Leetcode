class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalcandies=0;
        int n=status.size();
        vector<bool>opened(n,false);
        vector<bool>canbeopened(n,false);
        queue<int>q;

        for(int box: initialBoxes){
            canbeopened[box]=true;
            if(status[box]==1){
                q.push(box);
                opened[box]=true;
            }
        }
        while(!q.empty()){
            int box=q.front();
            q.pop();
            totalcandies+=candies[box];

            for(int key:keys[box]){
                status[key]=1;
                if(canbeopened[key] && !opened[key]){
                    q.push(key);
                    opened[key]=true;
                }
            }

            for(int next: containedBoxes[box]){
                canbeopened[next]=true;
                if(status[next] && !opened[next]){
                    q.push(next);
                    opened[next]=true;
                }
            }
        }
        return totalcandies;
    }
};