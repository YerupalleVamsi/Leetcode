class Solution {
public:
// ---  rec: ---
// int max_day;
//     int rec(vector<int>&present,int day,vector<int>&costs){
//         if(day>365 || day > max_day){
//             return 0;
//         }
//         if(present[day]==0)
//         {
//             return rec(present,day+1,costs);
//         }
//         int one = costs[0]+rec(present,day+1,costs);
//         int seven = costs[1]+rec(present,day+7,costs);
//         int monthly = costs[2]+rec(present,day+30, costs);
//         return min({one,seven,monthly});
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         // remember every dp is an optimization to recursive soln
//         // try to get recurrence relation 
//         vector<int>dp(365);
//         vector<int>present(366,0);
//         for(int i:days)
//         present[i]=1;
//         max_day=days.back();
//         int day=days[0];
//        return rec(present,day,costs);
//         }
int max_day;

    int rec(vector<int>&present,int day,vector<int>&costs,vector<int>&dp){
        if(day>365 || day > max_day){
            return 0;
        }
        
        if(present[day]==0)
        {
            return rec(present,day+1,costs,dp);
        }
        if(dp[day]!=-1) return dp[day];
        int one = costs[0]+rec(present,day+1,costs,dp);
        int seven = costs[1]+rec(present,day+7,costs,dp);
        int monthly = costs[2]+rec(present,day+30, costs,dp);
        return dp[day]=min({one,seven,monthly});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // remember every dp is an optimization to recursive soln
        // try to get recurrence relation 
        
        vector<int>present(366,0);
        for(int i:days)
        present[i]=1;
        max_day=days.back();
        int day=days[0];
        vector<int>dp(366,-1);
       return rec(present,day,costs,dp);
        }
    
};