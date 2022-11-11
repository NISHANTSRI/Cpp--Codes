class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int ans = 1;
        if(len == 1) return len;
        int first = 0;
        int sec = 0;
        
        while(sec < len){
            if(nums[first] != nums[sec]){
                first += 1;
                nums[first] = nums[sec];
                sec++;
                ans++;
            }else{
                sec++;
            }
        }
        return ans;
    }
};