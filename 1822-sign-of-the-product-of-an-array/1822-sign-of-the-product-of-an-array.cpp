class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0;
        for(auto it : nums){
            if(it > 0) pos++;
            if(it == 0) return 0;
        }
        
        return ((nums.size()-pos) %2 == 0) ? 1 : -1;
    }
};