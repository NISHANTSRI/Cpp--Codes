class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        
        vector<vector<int>> ans(n,vector<int>(m));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            
            q.pop();
            
            ans[r][c] = dist;
            
            int delrow[] = {0,0,1,-1};
            int delcol[] = {1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and 
                   !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        
        return ans;
    }
};