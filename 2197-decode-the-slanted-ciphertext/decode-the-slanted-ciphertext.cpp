class Solution {
public:
    string decodeCiphertext(string e, int r) {
        if(r==1) return e;
        //cout << e.size()<< endl;
        int c=e.size()/r;
        string res="";
        vector<vector<char>>grid(r,vector<char>(c));
        int row=0;
        int col=0;
        for(int i=0;i<e.size();i++){
                grid[row][col]=e[i];
                col++;
                if(col==c){
                    col=0;
                    row++;
                }
        }
        for(int i=0;i<c;i++){
            int curr_col=i;
            int curr_row=0;
            while(curr_col<c && curr_row<r){
                res+=grid[curr_row][curr_col];
                curr_row++;
                curr_col++;
            }

        }
        while (!res.empty() && res.back() == ' ') {
        res.pop_back();
    }
        return res;
    }
};