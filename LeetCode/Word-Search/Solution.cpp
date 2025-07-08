class Solution {
public:
    bool dfs(vector<vector<char>>&b,string word,int currindex,int r,int c){
        if(currindex==word.size()){
            return true;
        }
        if(r<0 || c<0 || r>=b.size() || c>=b[0].size() || b[r][c]!=word[currindex])
         return false;
        char vis=b[r][c];
        b[r][c]='1'; //is visited;
        bool valid=dfs(b, word, currindex + 1, r + 1, c) ||
                     dfs(b, word, currindex + 1, r - 1, c) ||
                     dfs(b, word, currindex + 1, r, c + 1) ||
                     dfs(b, word, currindex + 1, r, c - 1);
        b[r][c]=vis;
        return valid;

    }
    bool exist(vector<vector<char>>& board, string word) {
     for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,0,i,j))return true;
            }
           
        }
        return false;
    }
};