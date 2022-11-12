class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> ans;
        
        int n = v.size();
        int m = v[0].size();
        
        int c1 = 0,c2 = m-1,r1 = 0,r2 = n-1;
        
        while(r1 <= r2 && c1 <= c2){
            
            for(int i=c1;i<=c2;i++)
                ans.push_back(v[r1][i]);
            
            if(++r1 > r2) break;

            for(int i=r1;i<=r2;i++)
                ans.push_back(v[i][c2]);
            
            if(--c2 < c1) break;

            for(int i=c2;i>=c1;i--)
                ans.push_back(v[r2][i]);

            if(--r2 < r2) break;
            
            for(int i=r2;i>=r1;i--)
                ans.push_back(v[i][c1]);
            
            if(c1++ > c2) break;
           
           
        }
        return ans;
    }
};