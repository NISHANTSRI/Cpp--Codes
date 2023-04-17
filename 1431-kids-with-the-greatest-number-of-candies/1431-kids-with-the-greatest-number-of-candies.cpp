class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int chk = INT_MIN;
        
        for(int i=0;i<candies.size();i++){
            if(candies[i] > chk) chk = candies[i];
        }
        
        vector<bool> ans(candies.size(),false);
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= chk) ans[i] = true;
        }
        
        return ans;
    }
};