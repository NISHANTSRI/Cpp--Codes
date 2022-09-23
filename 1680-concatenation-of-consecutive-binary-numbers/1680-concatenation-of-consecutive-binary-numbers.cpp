class Solution {
public:
    long int solve(int n){
            long int pos = 0;
            while (n > 0) {
                n = n >> 1;
                pos++;
            }
            return pos;
    }

    int concatenatedBinary(int n) {
        long int mod = 1e9+7;
        long int ans = 0;
        for(int i=1;i<=n;i++){
            int position = solve(i);
            ans = ans << position;
            ans = (ans | i)%mod;
        }   
        return ans%mod;
    }

};