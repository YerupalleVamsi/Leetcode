class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        // o(n^3) :( 
        int cnt=0;
        for(int i=0;i<p.size();i++){
            for(int j=0;j<p.size();j++){
                if(i==j)continue;
                int Ax=p[i][0];
                int Ay=p[i][1];
                int Bx=p[j][0];
                int By=p[j][1];
                if(Ax<=Bx && Ay>=By){
                    bool found=true;
                
                for(int k=0;k<p.size();k++){    
                    if(k==i || k==j)continue;
                    int k_x=p[k][0];
                    int k_y=p[k][1];
                    if(Ax<=k_x && k_x<=Bx && Ay>=k_y && k_y>=By){
                        found=false;
                        break;
                        }
                }
                if(found)cnt++;
                }
            }
        }
        return cnt;
    }
};