class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // dfs doesnt work
        vector<bool>vis(1001,false);
        int op=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int s=q.size();
            while(s--){
            int curr = q.front();
            q.pop();
            if(curr==goal){
                return op;
            }
            if(curr<0 || curr>1000 ||vis[curr]){
                continue;
            }
            vis[curr]=true;
            for(int i=0;i<nums.size();i++){
                q.push(curr+nums[i]);
                q.push(curr-nums[i]);
                q.push(curr ^ nums[i]);
            }}
            op++;
        }
        return -1;

    }
};