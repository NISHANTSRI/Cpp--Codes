class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int lowest = 1e7;
        for(int i=0;i<n-2;i++){
            int first = i+1;
            int last = n-1;
            while(first < last){
                if(lowest == 1e7) lowest = nums[first] + nums[last] + nums[i];
                if(abs(target - (nums[first] + nums[last] + nums[i])) < abs(target-lowest) and lowest != 1e7)
                    lowest = nums[first] + nums[last] + nums[i];
                if(nums[first] + nums[last] + nums[i] > target)
                    last--;
                else
                    first++;
            }
        }
        
        return lowest;
    }
};