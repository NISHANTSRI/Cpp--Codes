class Solution {
public:
    string reverseWords(string s) {
        string temp;
        stringstream str(s);
        
        vector<string> ans;
        while(str >> temp)
            ans.push_back(temp);
        
        string ret;
        
        for(int i = ans.size()-1;i>=0;i--){
            ret += ans[i];
            if(i != 0)ret += " ";
        }
        return ret;
    }
};