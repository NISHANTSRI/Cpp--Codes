class Solution {
    
    int solve(int target,int maxDoubles){
        if(target == 1)
            return 0;
        if(maxDoubles == 0)
            return target-1;
        
        int x = INT_MAX;
        
        // if we have maxDouble in stock
        
        if(target%2 == 0 and maxDoubles){
            x = solve(target/2,maxDoubles-1);
            return x + 1;
        }
        // if we cannot half it directly just return the remainng terget
        
        x = solve(target-1,maxDoubles);
        return x + 1;
    }
    
public:
    int minMoves(int target, int maxDoubles) {
        return solve(target,maxDoubles);
    }
};