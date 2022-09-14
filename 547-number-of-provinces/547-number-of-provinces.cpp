class Solution {
    void dfs(int node,unordered_map<int,list<int>> &adjlist,vector<int>& vis){
        vis[node] = 1;
        
        for(auto it : adjlist[node]){
            if(!vis[it]){
                dfs(it,adjlist,vis);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>> adjlist;
        int n = isConnected.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 and i != j){
                    adjlist[i+1].push_back(j+1);
                    adjlist[j+1].push_back(i+1);
                }
            }
        }
        
        vector<int> vis(n+1,0);
        
        int province = 0;
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                province++;
                dfs(i,adjlist,vis);
            }
        }
        
        return province;
    }
};