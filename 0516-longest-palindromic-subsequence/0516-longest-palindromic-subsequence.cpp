class Solution {
    int f(int i,int j, string &s, string &t, vector<vector<int>> &dp){
        if(i < 0 or j < 0) return 0;
        if(s[i] == t[j]) return 1+f(i-1,j-1,s,t,dp);
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return f(s.length()-1,t.length()-1,s,t,dp);
    }
};