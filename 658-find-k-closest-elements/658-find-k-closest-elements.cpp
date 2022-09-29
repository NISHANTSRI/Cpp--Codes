class Node{
    public:
    int data;
    int diff;
    
    Node(int data, int diff){
        this->data = data;
        this->diff = diff;
    }
};

class compare{
    public:
    bool operator()(Node *a , Node* b){
        return a->diff < b->diff;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        priority_queue<Node* , vector<Node*> , compare> maxHeap;
        
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int d = abs(arr[i] - x);
            Node* nu = new Node(arr[i],d);
            
            if(maxHeap.size() < k) maxHeap.push(nu);
            else{
                if(maxHeap.top()->diff > nu->diff){
                    maxHeap.pop();
                    maxHeap.push(nu);
                }
                
                else continue;
            }
        }
        
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top()->data);
            maxHeap.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};