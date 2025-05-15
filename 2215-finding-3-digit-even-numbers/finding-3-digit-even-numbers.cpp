class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digitCount(10, 0);
        for (int digit : digits) digitCount[digit]++;

        vector<int> ans;

        for (int i = 100; i <= 999; i++) {
            int d1 = i / 100;
            int d2 = (i / 10) % 10;
            int d3 = i % 10;
            if (d3 % 2 != 0) continue; 
            vector<int> tempCount(10, 0);
            tempCount[d1]++;
            tempCount[d2]++;
            tempCount[d3]++;
            bool isValid = true;
            for (int d = 0; d < 10; d++) {
                if (tempCount[d] > digitCount[d]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) ans.push_back(i);
        }
        return ans;
    }
};
