class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
    
        map<pair<int,int>, map<int,int>> slopes; // slope,intercept,freq
        map<pair<int,int>, int> midpts; // midpoints , freq
        map<pair<int,int>, map<pair<int,int>,int>> mid_diff; // midpoints,slope,freq
        long long p = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                pair<int,int> slope;
                if (dx == 0)
                slope = {0, 1};         
                else if (dy == 0)
                slope = {1, 0};          
                else {
                    if (dx < 0) { dx = -dx; dy = -dy; }
                    int g = gcd(dx, dy);
                    slope = {dx/g, dy/g};    
                }
            long long intercept = 1LL * slope.second * x1 - 1LL * slope.first * y1;
                slopes[slope][intercept]++;

                int mx = x1 + x2, my = y1 + y2;
                p += midpts[{mx,my}] - mid_diff[{mx,my}][slope];
                midpts[{mx,my}]++;
                mid_diff[{mx,my}][slope]++;
            }
        }
        long long res = 0;
        for(auto &s : slopes){
            long long sum = 0;
            for(auto &it : s.second){
                long long cnt = it.second;
                res += cnt * sum;
                sum += cnt;
            }
        }

        return res - p;   
    }
};

