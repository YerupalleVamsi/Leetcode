class Solution {
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>pse(n);
        vector<int>nse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int res=0;
        for(int i=0;i<arr.size();i++){
            int L = i - pse[i];
            int R = nse[i] - i;
            res = (res + (1LL*L*R*arr[i])%MOD)%MOD;            
        }
        return res%MOD;
    }
    
};