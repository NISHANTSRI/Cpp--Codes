class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MAX,num2 = INT_MAX;
        int count1 = 0,count2 = 0;
        
        for(auto it:nums){
            if(it == num1)count1++;
            else if(it == num2) count2++;
            else if(count1 == 0) num1 = it,count1++;
            else if(count2 == 0) num2 = it,count2++;
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1) count1++;
            if(nums[i] == num2) count2++;
        }
        
        if(count1 > nums.size() / 3) ans.push_back(num1);
        if(count2 > nums.size() / 3) ans.push_back(num2);
        
        return ans;
    }
};