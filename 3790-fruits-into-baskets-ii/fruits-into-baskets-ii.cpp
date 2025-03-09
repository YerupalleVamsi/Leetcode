class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(); vector<int>visited(fruits.size(),0);
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
if(fruits[i]<=baskets[j]&&visited[j]!=1){
visited[j]=1;
        n--;break;}}
        }return n;
    }
};