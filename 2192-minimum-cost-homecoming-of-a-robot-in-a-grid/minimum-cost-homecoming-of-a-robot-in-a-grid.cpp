class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rc, vector<int>& cc) {
        if((startPos[0]==homePos[0]) &&(startPos[1]==homePos[1])){
            return 0;
        }
        int mc=0;
        if(startPos[0]<homePos[0]){
        for(int i=startPos[0]+1;i<=homePos[0];i++){
            mc+=rc[i];
        }}
        else{
            for(int i=startPos[0]-1;i>=homePos[0];i--)
            mc+=rc[i];
        }
        if(startPos[1]<homePos[1]){
        for(int i=startPos[1]+1;i<=homePos[1];i++){
            mc+=cc[i];
        }}
        else{
            for(int i=startPos[1]-1;i>=homePos[1];i--)
            mc+=cc[i];
        }
        
        
        return mc;
        
    }
};