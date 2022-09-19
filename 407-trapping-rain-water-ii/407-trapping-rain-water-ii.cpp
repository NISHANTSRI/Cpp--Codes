class Solution {
public:
    
    // the main idea is to shrik from the boundaries, while doning the traversall we find the lowesr height
    // and start shrinking forn it to the next bigger height,, if the next unvivited node is havong height lowe 
    //than tht od he lowert height from the prev one we can say that the water will be stoer dint it,
    
    
    int trapRainWater(vector<vector<int>>& h) {
        int row = h.size();
        int col = h[0].size();
        
        int vol = 0;
        // to check whelter we have visited the current node or not.
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        // to store the content of the elemnt and its position
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 or j==0 or i==row-1 or j==col-1){
                    q.push({h[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int minH = 0;
        
        while(!q.empty()){
            int curH = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            
            q.pop();
            
            minH = max(minH,curH);
            
            int dr[] = {0,0,1,-1};
            int dc[] = {1,-1,0,0};
            
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 and nr < row and nc >= 0 and nc < col and vis[nr][nc] == false){
                    q.push({h[nr][nc],{nr,nc}});
                    vis[nr][nc] = true;
                    
                    if(h[nr][nc] < minH){
                        vol += minH - h[nr][nc];
                    }
                }
            }
        }
        
        return vol;
    }
};