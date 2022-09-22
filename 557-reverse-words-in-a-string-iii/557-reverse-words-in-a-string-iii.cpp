class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        
        int n = s.length();
        
        string rev = "";
        
        for(int i=0;i<n;i++){
            if(s[i] != ' '){
                st.push(s[i]);
            }
            
            else{
                while(!st.empty()){
                    rev += st.top();
                    st.pop();
                }
                rev += " ";
            }
        }
        
        while(!st.empty()){
            rev += st.top();
            st.pop();
        }
        
        return rev;
    }
};