struct values{
    vector<string> data;
    vector<int> ts;
    int size = 0;
    
    values(){}
    values(int timestamp,string value){
        ts.push_back(timestamp);
        data.push_back(value);
        size++;
    }
    
    void add(int time,string val){
        ts.push_back(time);
        data.push_back(val);
        size++;
    }
    
    string find(int time){
        if(size == 0) return "";
        else{
            int ind = lower_bound(ts.begin(),ts.end(),time)-ts.begin();
            if(ind >= size) ind = size-1;

            while(ind > 0 and ts[ind] > time) ind--;

            if(ts[ind] <= time) return data[ind];

            else return "";
        }
        
    }
};

class TimeMap {
    map<string,values> map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].add(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        return map[key].find(timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */