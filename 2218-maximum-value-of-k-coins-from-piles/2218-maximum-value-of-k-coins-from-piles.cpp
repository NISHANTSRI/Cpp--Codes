class Solution {
    int f(int i,int k,vector<vector<int>> &piles,vector<vector<int>> &dp){
        if(i >= piles.size() or k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        // if we do not want ot take the coin
        dp[i][k] = f(i+1,k,piles,dp);
        
        // if we take a coin from piles or the single pile
        int curpile = 0;
        int s = piles[i].size();
        int iter = min(k,s);
        for(int j = 0;j < iter;j++ ){
            curpile += piles[i][j];
            dp[i][k] = max(dp[i][k],curpile + f(i+1,k-j-1,piles,dp));
        }
        
        return dp[i][k];
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size(),vector<int>(k+1,-1));
        return f(0,k,piles,dp);
    }
};