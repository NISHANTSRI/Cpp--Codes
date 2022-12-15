class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adjlist[n];
        for(auto it : pre){
            adjlist[it[0]].push_back(it[1]);
        }

        //int n = adjlist.size();
        queue<int> st;
        vector<int> inorder(n,0);

        for(int i=0;i<n;i++){
            for(auto it : adjlist[i]){
                inorder[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(inorder[i] == 0) st.push(i);
        }

        vector<int> ans;

        while(!st.empty()){
            int num = st.front();
            st.pop();
            for(auto it : adjlist[num]){
                inorder[it]--;
                if(inorder[it] == 0) st.push(it);
            }

            ans.push_back(num);
        }
        vector<int> emp;
        reverse(ans.begin(),ans.end());
        return ans.size() == n ? ans : emp;
    }
};