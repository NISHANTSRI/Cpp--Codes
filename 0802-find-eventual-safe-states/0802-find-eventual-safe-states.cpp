class Solution {
public:
    bool checkdfs(int node,vector<vector<int>>& graph,vector<int> &check, vector<int> &vis,
    vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(checkdfs(it,graph,check,vis,pathVis) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> check(num);
        vector<int> ans;
        cout<<num<<endl;
        vector<int> vis(num,0);
        vector<int> pathVis(num,0);

        for(int i=0;i<num;i++){
            if(!vis[i]){
                checkdfs(i,graph,check,vis,pathVis);
            }
        }

        for(int i=0;i<num;i++){
            if(check[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};