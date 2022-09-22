class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int freshCnt = 0;
        int cnt = 0;
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) freshCnt++;
            }
        }
        
        int time = 0;
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            
            int delrow[] = {0,0,1,-1};
            int delcol[] = {1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        cout << freshCnt <<" "<< cnt<<endl;
        if(cnt != freshCnt) return -1;
        
        return time;
    
    }
};