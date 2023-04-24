class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {        
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size() > 1){
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            if(f == s) continue;
            else{
                pq.push(abs(f-s));
            }
        }
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};