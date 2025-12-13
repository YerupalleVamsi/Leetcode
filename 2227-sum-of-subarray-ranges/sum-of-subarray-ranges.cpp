class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
        int n = nums.size();
        vector<int>nse(n),nge(n),pse(n),pge(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            pse[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            pge[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nge[i] = st.empty()? n : st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++){
            int LS = i - pse[i];
            int RS = nse[i] - i;
            int LG = i - pge[i];
            int RG = nge[i] - i;
            res+=(1LL*LS*RS*nums[i]);
            res-=(1LL*LG*RG*nums[i]);
        }
        return res;

    }
};