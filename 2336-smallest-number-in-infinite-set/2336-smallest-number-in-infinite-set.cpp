class SmallestInfiniteSet {
    //int isPresent[1001];
    set<int> st;
    int currnum;
public:
    SmallestInfiniteSet() {
        currnum = 1;
        //memset(inPresent,0,sizeof(isPresent));
    }
    
    int popSmallest() {
        int ans;
        
        if(!st.empty()){
            ans = *st.begin();
            st.erase(st.begin());
        }
        
        else{
            ans = currnum;
            currnum++;
        }
        
        return ans;
    }
    
    void addBack(int num) {
        if(st.find(num) != st.end() or currnum <= num) {
            return;
        }
        
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */