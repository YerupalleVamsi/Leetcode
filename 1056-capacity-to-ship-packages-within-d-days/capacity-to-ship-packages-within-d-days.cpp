class Solution {
public:
    bool isvalid(const vector<int>& weights, int days, int mincap) {
        int ndays = 1, wts = 0;
        for (int w : weights) {
            if (wts + w > mincap) {
                ndays++;
                wts = w; 
                if (ndays > days) return false; 
            } else {
                wts += w;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());  
        int high = accumulate(weights.begin(), weights.end(), 0); 

        while (low < high) {
            int mid = (low + high) / 2;  
            if (isvalid(weights, days, mid)) {
                high = mid;  
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
};
