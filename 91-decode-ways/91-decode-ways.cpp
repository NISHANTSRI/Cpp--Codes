class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);

        dp[0] = 1; 
        dp[1] = (s[0] != '0');

        for(int i = 2 ; i <= s.size() ; i++){
            dp[i] = 0;
            if(s[i-1] != '0'){
                dp[i] += dp[i-1];
            }

            if(stoi(s.substr(i-2,2)) <= 26 && stoi(s.substr(i-2,2)) >= 10 && s[i-2] != 0){
                dp[i] += dp[i-2];
            }
        }

        return dp[s.size()];
    }
};