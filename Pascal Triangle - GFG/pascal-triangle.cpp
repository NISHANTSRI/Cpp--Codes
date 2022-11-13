//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        ll mod = 1e9 + 7;
        vector<vector<ll>> nums(n);
        
        for(ll i=0;i<n;i++){
            nums[i].resize(i+1);
            nums[i][0] = nums[i][i] = 1;
            for(ll j=1;j<i;j++){
                nums[i][j] = (nums[i-1][j-1] + nums[i-1][j])%mod;
            }
        }
        
        return nums[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends