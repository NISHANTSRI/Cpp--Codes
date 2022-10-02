class Solution {
public:
    
    long long mod = 1000000007;
    int arr[31][1001] = {};
    int numRollsToTarget(int n, int k, int target) {
        if(target==0 && n==0){
            return 1;
        }
        
        if(n*k<target || target<n || target<=0){
            return 0;
        }
        if(arr[n][target]!=0){
            return arr[n][target];
        }
        int ans=0;
        for(int i=1; i<=k; i++){
            ans = (ans + numRollsToTarget(n-1, k, target-i))%mod;
            
        }
        arr[n][target] = ans;
       return arr[n][target]; 
    }
        
    
};