class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [num, _] : freq) pq.push(num);
        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();
            if (freq[first] == 0) continue; 
            int count = freq[first];
            for (int i = 0; i < k; i++) {
                int curr = first + i;
                if (freq[curr] < count) return false;
                freq[curr] -= count;
                if (freq[curr] > 0 && curr != first) pq.push(curr); // might still be useful later
            }
        }

        return true;
    }
};