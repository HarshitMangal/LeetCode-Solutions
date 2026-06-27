class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    unordered_map<char,int>map;
    for(int i=0;i<jewels.length();i++){
        map[jewels[i]]++;
    }
    int count=0;
    for(auto x:stones){
        if(map.find(x)!=map.end()){
            count++;
        }
    }
    return count;
        
    }
};