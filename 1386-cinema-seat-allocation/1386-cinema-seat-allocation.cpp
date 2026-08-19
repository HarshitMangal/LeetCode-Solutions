class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        unordered_map<int,set<int>>mp;
        for(auto it:arr){
            int u=it[0];
            int v=it[1];
            mp[u].insert(v);
        }
        int ans=(n-mp.size())*2;
        for(auto it:mp){
            auto&st=it.second;
            bool left=!(st.count(2)||st.count(3)||st.count(4)||st.count(5));
            bool mid=!(st.count(4)||st.count(5)||st.count(6)||st.count(7));
            bool right=!(st.count(6)||st.count(7)||st.count(8)||st.count(9));
            if(left&&right){
                ans+=2;
            }
            else if(left||right||mid){
                ans+=1;
            }
        }
        return ans;
    }
};