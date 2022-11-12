class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 1;
        for(auto it : nums){
            s.erase(it);
            int prev = it-1,next = it+1;
            while(s.find(prev)!=s.end()) s.erase(prev--);
            while(s.find(next)!=s.end()) s.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};