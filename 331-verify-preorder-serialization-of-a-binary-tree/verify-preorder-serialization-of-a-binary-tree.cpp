class Solution {
public:
    int solve(int i,vector<string> &BT){
       if(i>=BT.size()) return -1;
       if(BT[i]=="#") return i+1;
       int left = solve(i+1,BT);
       if(left==-1) return -1;
       int  right = solve(left,BT);
       if(right==-1) return -1;
       return right;
    }
    bool isValidSerialization(string preorder) {
        if(preorder.size()==1) return preorder[0]=='#'? true:false;
        vector<string>BT;
         string s;
        for (char c : preorder) {
            if (c == ',') {
                BT.push_back(s);
                s = "";
            } else {
                s += c;
            }
        }
        BT.push_back(s); 
        int next = solve(0,BT);
        return next == BT.size();
    }
};