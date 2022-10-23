class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int positive,xorall=0,repeatedelement;
        for(int i=0;i<nums.size();i++){
            positive = abs(nums[i]);
            nums[positive-1]*=-1;
            if(nums[positive-1]>0){repeatedelement=positive;}
                
            xorall ^=positive;
            xorall ^=(i+1);
        }
        xorall ^=repeatedelement;
        return {repeatedelement,xorall};
    }
};