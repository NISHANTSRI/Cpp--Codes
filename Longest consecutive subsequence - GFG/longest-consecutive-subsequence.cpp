//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int N)
    {
      unordered_set<int> s;
      for(int i=0;i<N;i++){
          s.insert(nums[i]);
      }
      
      int res = 1;
      
      for(int i=0;i<N;i++){
          s.erase(nums[i]);
          int prev = nums[i]-1,next = nums[i]+1;
          while(s.find(prev) != s.end()) s.erase(prev--);
          while(s.find(next) != s.end()) s.erase(next++);
          res = max(res,next-prev-1);
      }
      
      return res;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends