class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 or i == n-1 or j == 0 or j == m-1) and board[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            int delrow[] = {0,0,-1,1};
            int delcol[] = {-1,1,0,0};
            
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
                if(nrow >=0 and nrow < n and ncol >= 0 and ncol < m and
                   board[nrow][ncol] == 'O' and !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' and !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};