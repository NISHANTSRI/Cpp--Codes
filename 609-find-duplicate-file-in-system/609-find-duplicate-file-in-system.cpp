class Solution {
    unordered_map<string, vector<string>> mp;
    void fun(string s) {
        int len = s.size();
        string root = "", str="";
        vector<string> ans;
        int i=0;
        while(s[i] != ' ')   root += s[i++];
        i++;
        for(;i<len;i++) {
            while(i<len && s[i]!='(')   str += s[i++];
            string path = root+'/'+str;
            str="";
            i++;
            while(i<len && s[i]!=')')   str += s[i++];
            mp[str].push_back(path);
            i++;
            str="";
        }
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        for(auto s: paths)  fun(s);
        for(auto p: mp) {
            if(p.second.size()>1)
                ans.push_back(p.second);
        }
        return ans;
    }
};