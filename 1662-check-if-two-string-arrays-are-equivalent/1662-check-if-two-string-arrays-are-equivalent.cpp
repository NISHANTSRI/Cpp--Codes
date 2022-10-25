class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "";
        
        for(auto it: word1){
            first += it;
        }
        
        string second = "";
        
        for(auto it: word2){
            second += it;
        }
        
        if(first != second) return false;
        
//         map<char,int> mpp;
        
//         for(int i=0;i<first.size();i++){
//             mpp[first[i]]++;
//         }
        
//         for(int i=0;i<second.size();i++){
//             mpp[second[i]]--;
//             if(mpp[second[i]] < 0) return false;
//         }
        
        return true;
    }
};