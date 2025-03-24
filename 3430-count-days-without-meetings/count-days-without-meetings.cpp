class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int cnt = 0, last = 1;
        for (auto& meeting : meetings) {
            int s = meeting[0], e = meeting[1];
            if (s > last) {
                cnt += s - last;
            }
            last = max(last, e + 1);
        }

        if (days >= last) {
            cnt += days - last + 1;
        }

        return cnt;
    }
};
