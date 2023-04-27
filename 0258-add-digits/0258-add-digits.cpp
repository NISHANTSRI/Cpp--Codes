class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int i = 0;
        while(num > 0){
            i += num % 10;
            num = num/10;
            
            if(num == 0 and i > 9){
                num = i;
                i = 0;
            }
        }
        
        return i;
    }
};