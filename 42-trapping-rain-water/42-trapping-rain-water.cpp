class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left=0;
        int right=n-1;
        int maxL = 0;
        int maxR = 0;
        int wtr = 0;
        
        while(left <= right){
            if(h[left] <= h[right]){
                if(h[left] > maxL) maxL = h[left];
                else wtr += (maxL - h[left]);
                left++;
            }else{
                if(h[right] > maxR) maxR = h[right];
                else wtr += (maxR - h[right]);
                right--;
            }
        }
        return wtr;
    }
};