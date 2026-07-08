class LFUCache {
public:
    // key -> {{value, frequency}, lastUsedTime}
    unordered_map<int, pair<pair<int,int>, int>> mp;

    int cap;
    int timer = 0;

    LFUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        mp[key].first.second++;   // frequency++
        mp[key].second = ++timer; // update last used time

        return mp[key].first.first;
    }

    void put(int key, int value) {

        if(cap == 0)
            return;

        // Key already exists
        if(mp.find(key) != mp.end()) {
            mp[key].first.first = value;   // update value
            mp[key].first.second++;        // frequency++
            mp[key].second = ++timer;      // update time
            return;
        }

        // Cache full
        if(mp.size() == cap) {

            int delKey = -1;
            int minFreq = INT_MAX;
            int minTime = INT_MAX;

            for(auto &it : mp) {

                int freq = it.second.first.second;
                int time = it.second.second;

                if(freq < minFreq) {
                    minFreq = freq;
                    minTime = time;
                    delKey = it.first;
                }
                else if(freq == minFreq && time < minTime) {
                    minTime = time;
                    delKey = it.first;
                }
            }

            mp.erase(delKey);
        }

        // Insert new key
        mp[key] = {{value, 1}, ++timer};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */