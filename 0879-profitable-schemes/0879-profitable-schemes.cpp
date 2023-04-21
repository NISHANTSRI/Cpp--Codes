class Solution {
    int mod = 1e9 + 7;
    int dp[101][101][101];
    int f(int i, int n, int p, int minProfit, vector<int>& group, vector<int>& profit){
        if(i >= group.size()){
            if(p >= minProfit) return 1;
            else return 0;
        }
        
        if(dp[i][n][p] != -1) return dp[i][n][p];
        
        // do not want index i
        int notTook = f(i+1,n,p,minProfit,group,profit);
        int took = 0;
        if(n - group[i] >= 0){
            took += f(i+1,n-group[i],min(p+profit[i],minProfit),minProfit,group,profit);
        }
        
        return dp[i][n][p] = (took + notTook)%mod;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) { 
        memset(dp,-1,sizeof(dp));
        return f(0,n,0,minProfit,group,profit)%mod;
    }
};