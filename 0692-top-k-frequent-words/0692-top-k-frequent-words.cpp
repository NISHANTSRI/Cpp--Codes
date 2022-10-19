class qual{
    public:
    string data;
    int freq;
    qual(){}
    
    qual(string a, int b){
        this->data = a;
        this->freq = b;
    }
};

class compare{
    public:
    bool operator()(qual *a, qual *b){
        if(a->freq > b->freq) return true;
        if(a->freq < b->freq) return false;
        else{
            return a->data < b->data;
        }
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto it: words){
            mpp[it]++;
        }
        
        priority_queue<qual*,vector<qual*>, compare> pq;
        vector<qual*> v;
        
        for(auto it:mpp){
            qual *temp = new qual(it.first,it.second);
            v.push_back(temp);
        }
        
        for(auto it : v){
            //cout << it->data << " " ;
            if(pq.size() < k) pq.push(it);
            else{
                if(pq.top()->freq < it->freq) {
                    pq.pop();
                    pq.push(it);
                }
                else if(pq.top()->freq == it->freq and pq.top()->data > it->data){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
        //cout << endl;
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top()->data);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        //for(auto it: ans) cout << it<< " ";
        return ans;
    }
};