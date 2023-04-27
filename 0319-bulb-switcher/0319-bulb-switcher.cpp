class Solution {
public:
    int bulbSwitch(int n) {
        double num = sqrt(n);
        double f = floor(num);
        
        return (int)f;
    }
};