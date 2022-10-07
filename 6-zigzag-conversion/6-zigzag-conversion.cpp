class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows == 1) return s;
        
        int inc = 2*(numRows-1);
        string ans = "";
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j += inc){
                ans += s[j];
                if(i > 0 and i < numRows-1 and j+inc-2*i < n){
                    ans += s[j+inc-2*i];
                }
            }
        }
        
        return ans;
    }
};