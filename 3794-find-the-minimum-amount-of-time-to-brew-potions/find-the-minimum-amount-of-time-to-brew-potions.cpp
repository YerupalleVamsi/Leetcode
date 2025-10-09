class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long >pre(n,0);
        
        for(int i=0;i<m;i++){
            pre[0] += skill[0] * mana[i];
            for(int j=1;j<n;j++){
                pre[j] = max(pre[j],pre[j-1]) + 1LL *mana[i] * skill[j]; 
            }
            for(int j = n-1;j>0;j--){
                pre[j-1] = pre[j] - 1LL*mana[i] * skill[j];
            }
        }
        return pre[n-1];
    }
};