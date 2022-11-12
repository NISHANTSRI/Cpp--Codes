//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &v, int n, int m, int k)
    {
        vector<int> ans;
        
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
        
        return ans[k-1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends