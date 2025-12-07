class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int,int>p={0,0};
        int dir = 1; // 1-N 2-E 3-S 4-W
        for(auto it:instructions){
            if(it=='G'){
                if(dir==1) p.second++;
                else if(dir==2) p.first++;
                else if(dir==3) p.second--;
                else p.first--;
            }
            else if(it=='L'){
                dir--;
                if(dir==0) dir=4;
            }
            else
            {
                dir++;
                if(dir>4) dir=1;
            }
           
        }
        if((p.first==0 && p.second ==0 ) || dir!=1)return true;
        return false;
    }
};