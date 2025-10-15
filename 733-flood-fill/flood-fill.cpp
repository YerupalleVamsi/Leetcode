class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int  n = image.size();
        int m = image[0].size();
        vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] =  true;
        int red = image[sr][sc];
        while(!q.empty()){
            int s = q.size();
            while(s--){
            auto [X,Y] = q.front();
            q.pop();
           int x[] = {-1, 1, 0, 0};
            int y[] = {0, 0, -1, 1};
            int curr = image[X][Y];
            for(int i=0;i<4;i++){
                int dx = X+x[i];
                int dy = Y+y[i];
                if(dx>=0 && dx < n && dy >=0 && dy < m && !vis[dx][dy] && image[dx][dy] == red ){
                    vis[dx][dy] = true;
                    image[dx][dy] = color;
                    q.push({dx,dy});}
            }}
        }
        image[sr][sc]=color;
        return image;
    }
};