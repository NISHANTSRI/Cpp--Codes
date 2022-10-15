import sys

class Solution:
    def minMoves(self, target: int, maxdoubles: int) -> int:
        
        def solve(target :int , maxdoubles :int):
            if target == 1:
                return 0
            
            if maxdoubles == 0:
                return target-1
            
            x = sys.maxsize
            
            if maxdoubles and target % 2 == 0:
                x = solve(int(target/2),maxdoubles-1)
                return x+1
            
            x = solve(target-1,maxdoubles)
            return x+1
        
        return solve(target,maxdoubles)
        