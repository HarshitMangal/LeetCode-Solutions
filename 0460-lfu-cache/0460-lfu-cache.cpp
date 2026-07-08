class LFUCache {
public:
  int capacity;
  int time=0;
  int fre=0;
  unordered_map<int,pair<pair<int,int>,int>>mp; //{ key,{value,fre},timestamp}
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
         if(mp.find(key)==mp.end()) return -1;
         mp[key].first.second++;
         mp[key].second=++time;
         return mp[key].first.first;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].first.first=value;
            mp[key].first.second++;
            mp[key].second=++time;
            return;
        }
          if(mp.size()==capacity){
        int minfre=INT_MAX;
        int mintime=INT_MAX;
         int deletekey=-1;
         for(auto it:mp){
             int fre=it.second.first.second;
             int time=it.second.second;
             if(fre<minfre){
                minfre=fre;
                mintime=time;
                deletekey=it.first;
             }
             else if(fre==minfre&&time<mintime){
                mintime=time;
                deletekey=it.first;
             }
         }
         mp.erase(deletekey);
    }
    mp[key]={{value,1},++time};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */