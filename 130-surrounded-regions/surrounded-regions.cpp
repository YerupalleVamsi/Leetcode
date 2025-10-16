class Solution {
public:
    void dfs(vector<vector<char>>&gr,int i, int j){
        if(i < 0 || j < 0 || i >= gr.size() || j >= gr[0].size() ||gr[i][j] == 'V' || gr[i][j] == 'X') return;
        gr[i][j] = 'V';
        dfs(gr,i+1,j);
        dfs(gr,i,j+1);
        dfs(gr,i-1,j);
        dfs(gr,i,j-1);
        return;
    }
    void solve(vector<vector<char>>& gr) {
        int  R = gr.size();
        int C = gr[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if((i==0 || j==0 || i==R-1 || j==C-1) &&gr[i][j] == 'O'){
                    dfs(gr,i,j);
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(gr[i][j] == 'O'){
                    gr[i][j] = 'X';
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(gr[i][j] == 'V'){
                    gr[i][j] = 'O';
                }
            }
        }
    }
};