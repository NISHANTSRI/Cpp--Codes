class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        int flag = 1;
        string ans = "";
        while(ptr1 < n and ptr2 < m){
            if(flag == 1){
                ans += word1[ptr1];
                ptr1++;
                flag = 2;
            } 
            if(flag == 2){
                ans += word2[ptr2];
                ptr2++;
                flag = 1;
            }
        }
        
        if(ptr1 == n){
            ans += word2.substr(ptr2,m-ptr2+1);
        }
        
        if(ptr2 == m){
            ans += word1.substr(ptr1,n-ptr1+1);
        }
        
        return ans;
    }
};