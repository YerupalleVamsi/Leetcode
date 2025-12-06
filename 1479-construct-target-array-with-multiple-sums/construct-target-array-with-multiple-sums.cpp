class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq(target.begin(),target.end());
        long long sum=0;

        for(auto it:target)
        sum+=it;

        while(1){
            int x = pq.top();pq.pop();
            sum-=x;
            if(x==1 || sum==1) return true;
            if(sum > x || sum==0 || x%sum==0) return false;
            x%=sum;
            sum+=x;
            pq.push(x);
        }
        return true;
    }
};