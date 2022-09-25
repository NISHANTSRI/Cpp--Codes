class Solution {
    int f(int ind,int buy,int t,vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || t == 0) return 0;
        if(dp[ind][buy][t] != -1) return dp[ind][buy][t];
        if(buy==1 and t >= 1)
            return dp[ind][buy][t] = max(-prices[ind]+f(ind+1,0,t,prices,dp),f(ind+1,1,t,prices,dp));
        
        return dp[ind][buy][t] = max(prices[ind]+f(ind+1,1,t-1,prices,dp),f(ind+1,0,t,prices,dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};