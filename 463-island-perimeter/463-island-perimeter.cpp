class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int num = 0;
                    for(int k=0;k<4;k++){
                        int nrow = i+delrow[k];
                        int ncol = j+delcol[k];
                        
                        if(nrow >= 0 and nrow < n and ncol >= 0 
                           and ncol < m and grid[nrow][ncol] == 1){
                            num++;
                        }
                    }
                    
                    q.push({4,num});
                }
            }
        }
        
        int perimtr = 0;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            //cout<<front.first<<" "<<front.second<<" ";
            perimtr += front.first;
            perimtr -= front.second;
        }
        
        return perimtr;
    }
};