class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t=0;
        int n = tickets.size();
        int i=0;
        while(tickets[k]!=0){
            if(tickets[i]>0){
            t++;
            tickets[i]--;
            }
            i=((i+1)%n);
        }
        return t;
    }
};