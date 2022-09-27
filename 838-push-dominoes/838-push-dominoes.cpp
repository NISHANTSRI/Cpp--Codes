class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        
        queue<pair<char,int>> q;
        
        for(int i=0;i<n;i++){
            if(dom[i] == 'L' or dom[i] == 'R'){
                q.push({dom[i],i});
            }
        }
        
        while(!q.empty()){
            char pos = q.front().first;
            int ind = q.front().second;
            q.pop();
            
            if(pos == 'L' and ind > 0 and dom[ind-1] == '.'){
                dom[ind-1] = 'L';
                q.push({dom[ind-1],ind-1});
            }
            
            else if(pos == 'R'){
                if(dom[ind+1] == '.' and ind+1 < n){
                    if(ind+2 < n and dom[ind+2] == 'L')
                        q.pop();
                    else{
                        dom[ind+1] = 'R';
                        q.push({dom[ind+1],ind+1});
                    }
                }
            }
        }
        
        return dom;
    }
};