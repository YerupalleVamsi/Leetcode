class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int i = 0;
        int n = events.size();
        int cnt = 0;
        int lastDay = 0;
        for (auto& evnt : events) {
            lastDay = max(lastDay, evnt[1]);
        }
        for (int day = 1; day <= lastDay; day++) {
            // Add all events starting currday
            while (i < n && events[i][0] == day) {
                min_heap.push(events[i][1]);
                i++;
            }
            // we have to remove the events that cannot be attended like niggaKarya
            while (!min_heap.empty() && min_heap.top() < day) {
                min_heap.pop();
            }
            // attend remaining
            if (!min_heap.empty()) {
                min_heap.pop();
                cnt++;
            }
        }

        return cnt;
    }
};