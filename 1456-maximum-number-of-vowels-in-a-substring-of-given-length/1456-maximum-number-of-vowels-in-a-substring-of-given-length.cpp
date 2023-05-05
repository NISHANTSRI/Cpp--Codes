class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int c=0;
        int maxi = INT_MIN;
        while(j<s.length())
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            {
                c++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
                maxi = max(maxi,c);
                if(s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u')
                {
                    c--;
                }
                i++;
                j++;
            }
        } 
        maxi = max(maxi,c);
        return maxi;
    }
};