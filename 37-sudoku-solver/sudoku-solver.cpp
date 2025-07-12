class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
       solver(board); 
    }
    bool solver(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(c,board,i,j)){
                            board[i][j]=c;
                            if(solver(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    bool isvalid(char num,vector<vector<char>>&board,int r,int c){
        
        for(int i = 0; i < 9; i++) {
    if(board[i][c] == num || board[r][i] == num) return false;
}
        for(int i=0;i<9;i++){
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == num)
            return false;
        }
        return true;
    }
};