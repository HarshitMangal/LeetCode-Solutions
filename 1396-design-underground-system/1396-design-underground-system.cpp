class UndergroundSystem {
public:
   unordered_map<int,pair<string,int>>mp;  //{id,{checkin,time}}
   unordered_map<string,pair<long long,int>>mp1;  // {} { totaltime,count}

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
         mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start=mp[id].first;
        int starttime=mp[id].second;
        string key=stationName+'#'+start;
        int time=t-starttime;
        mp1[key].second++;
        mp1[key].first+=time;

    }
    
    double getAverageTime(string startStation, string endStation) {
         string key=endStation+'#'+startStation;
         long long totaltime=mp1[key].first;
         int count=mp1[key].second;
          return (double)totaltime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */