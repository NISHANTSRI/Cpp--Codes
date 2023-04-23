class Solution {
    int mod = 1e9 + 7;
    
    int f(string &s, int k, int idx, vector<int> &dp){
        if(idx >= s.size()) return 1;
        
        if(s[idx] == '0') return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        long int ways = 0 , currnum = 0;
        
        for(int i=idx;i<s.size();i++){
            currnum = currnum*10 + s[i]-'0';
            
            if(currnum > k) break;
            
            ways = (ways + f(s,k,i+1,dp))%mod;
        }
        
        return dp[idx] = ways;
    }
    
public:
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(),-1);
        return f(s,k,0,dp);
    }
};