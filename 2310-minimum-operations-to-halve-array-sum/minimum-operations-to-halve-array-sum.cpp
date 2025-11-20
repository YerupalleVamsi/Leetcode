class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum  = 0;
        for(auto it:nums){
            pq.push((double)it);
            sum+=it;}
        double tar = sum/2;
        int op=0;
        while(!pq.empty()){
            if(sum<=tar) return op;
            double num = pq.top();pq.pop(); 
            num=num/2;
            sum-=num;
            pq.push(num);
            op++;
        }
        return -1;
    }
};