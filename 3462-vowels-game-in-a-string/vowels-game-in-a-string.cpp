class Solution {
public:
    bool doesAliceWin(string s) {
        int vows=0;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vows++;
            }
        }
        if(vows%2==1){
            return true;
        }
        if(vows==0)return false;
        return true;
    }
};