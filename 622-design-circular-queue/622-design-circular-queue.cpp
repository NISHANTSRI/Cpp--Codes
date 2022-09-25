class MyCircularQueue {
    list<int> q;
    int s;
public:
    MyCircularQueue(int k) {
        s = k;
    }
    
    bool enQueue(int value) {
        if(q.size() < s){
            q.push_back(value);
            return true;
        }else return false;
    }
    
    bool deQueue() {
        if(!q.empty()){
            q.pop_front();
            return true;
        }
        else return false;
    }
    
    int Front() {
        if(!q.empty()) return q.front();
        else return -1;
    }
    
    int Rear() {
        if(!q.empty()) return q.back();
        else return -1;
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        if(q.size() == s) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */