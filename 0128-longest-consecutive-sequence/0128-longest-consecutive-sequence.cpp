class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int>st(nums.begin(),nums.end());
        int maxi=0;
        for( auto it:st){
            int  val=it-1;
            if(st.find(val)==st.end()){

            int count=0;
            while(st.count(val+1)){
                count++;
                val=val+1;

            }
            maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};