class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int count = 0;
        int n=colors.size();
        for (int i = 1; i < n+k-1; i++) {
            if (colors[i%n] == colors[(i - 1)%n])
                count=i;
            if(i-count+1>=k) ans++; }

        return ans;
    }
};

