class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
     int n = energy.size();
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            energy[i] = energy[i] + (i + k < n ? energy[i + k] : 0);
            if(energy[i] > maxi) {
                maxi = energy[i];
            }
        }
        return maxi;
    }
};