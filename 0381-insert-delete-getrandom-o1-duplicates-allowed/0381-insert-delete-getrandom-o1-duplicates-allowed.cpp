class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
      arr.push_back(val);
      mp[val].insert(arr.size()-1);
      if(mp[val].size()==1) return true;
      return false;

    }
    
    bool remove(int val) {
        if(mp[val].empty())
            return false;

        int idx = *mp[val].begin();
        mp[val].erase(idx);

        int last = arr.back();

        if(idx != arr.size() - 1){

            arr[idx] = last;

            mp[last].erase(arr.size() - 1);
            mp[last].insert(idx);
        }

        arr.pop_back();

        return true;
    }
    
    int getRandom() {
          int idx = rand() % arr.size();
         return arr[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */