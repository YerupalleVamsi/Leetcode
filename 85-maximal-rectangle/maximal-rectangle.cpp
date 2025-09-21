class Solution {
public:
int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[i] < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1; // if empty no prev found that is lesser so we can form from 0 to i width=i :RSE-LSE-1
                area = max(area, height * width);
            }
            st.push(i);
        }
        // no NSE found for these 
        while (!st.empty()) {
            int height = h[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1; //can form upto n:LSE-RSE-1 but LSE is n
            area = max(area, height * width);
        }

        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> heights(c, 0); 
    int maxi = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == '1')
                heights[j] += 1;   
            else
                heights[j] = 0;   // not base no height without base how can we construct bru
        }
        int curr = largestRectangleArea(heights);
        maxi = max(maxi, curr);
    }
    return maxi;
}
};