class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX,mid = INT_MAX;
        for(auto it: nums){
            if(it <= left)
                left = it;
            else if(it <= mid)
                mid = it;
            
            else
                return true;
        }
        
        return false;
    }
};