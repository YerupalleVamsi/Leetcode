class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int totalcandies=0;
        bool open=true;
        while(!initialBoxes.empty() && open){
            open=false;
            vector<int>nextBoxes;
            for(int idx:initialBoxes){
                if(status[idx]){
                    open=true;
                    nextBoxes.insert(end(nextBoxes),begin(containedBoxes[idx]),end(containedBoxes[idx]));
                    for(int key:keys[idx]) status[key]=1;
                    totalcandies+=candies[idx];
                }
                else{
                    nextBoxes.push_back(idx);
                }
            }
            swap(initialBoxes,nextBoxes);
        }
        return totalcandies;
       
    }
};