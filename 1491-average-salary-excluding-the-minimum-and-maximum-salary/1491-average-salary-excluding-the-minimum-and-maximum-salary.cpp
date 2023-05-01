class Solution {
public:
    double average(vector<int>& salary) {
        double ans;
        int lowest = INT_MAX;
        int maxsal = INT_MIN;
        int sumsal = 0;
        
        for(int i=0;i<salary.size();i++){
            sumsal += salary[i];
            lowest = min(lowest,salary[i]);
            maxsal = max(maxsal,salary[i]);
        }
        
        sumsal -= (lowest+maxsal);
        
        return (double)sumsal / (salary.size()-2);
    }
};