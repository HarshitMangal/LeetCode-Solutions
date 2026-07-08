class LRUCache {
public: 
    unordered_map<int,pair<int,int>>mp; // {key,{value,last tyime used}}
    int cap;
    int rank=0;
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
          mp[key].second=++rank;
          return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]={value,++rank};
            return ;
        }
        
         if(mp.size() == cap) {

            int leastTime = INT_MAX;
            int delKey = -1;

            for(auto &it : mp) {
                if(it.second.second < leastTime) {
                    leastTime = it.second.second;
                    delKey = it.first;
                }
            }

            mp.erase(delKey);
        }
           mp[key] = {value, ++rank};

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */