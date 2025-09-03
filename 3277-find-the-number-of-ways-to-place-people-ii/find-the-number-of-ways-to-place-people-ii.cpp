class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int cnt=0;
        for(int i=0;i<n;i++){
            // top-left
            int x1=points[i][0];
            int y1=points[i][1];
            int y_max=INT_MIN; 
            for(int j=i+1;j<n;j++){
                // bottom -right
                int x2=points[j][0];
                int y2=points[j][1];
                if(y2>y1)continue; // skip 
                if(y2>y_max)
                {cnt++;
                y_max=y2;}           }
        }
        return cnt;
    }
};