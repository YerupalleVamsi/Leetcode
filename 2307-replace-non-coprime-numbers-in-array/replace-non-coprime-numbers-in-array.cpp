class Solution {
public:

    int g_help(int a,int b){
        return b==0? a: g_help(b,a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>res;
        stack<long long>st;
        for(int i=0;i<nums.size();i++){
            long long x=nums[i];
            while(!st.empty() && g_help(st.top(),x)>1){
                long long t=st.top();
                x = (t*x)/(g_help(t,x));
                st.pop();
            }
            st.push(x);
        }
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            res.push_back(tp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};