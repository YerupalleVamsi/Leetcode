class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int total =accumulate(apple.begin(),apple.end(),0);
        int cnt=0;
        for(int i=0;i<capacity.size() && total>0;i++){
            total-=capacity[i];
            cnt++;
        }
        return cnt;
    }
};