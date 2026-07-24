class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int ele=st.size();
        int ans=0;
        unordered_map<int,int>fre;
        int i=0;
        for(int j=0;j<n;j++){
            fre[nums[j]]++;
        while(fre.size()==ele){
             ans+=(n-j);
            fre[nums[i]]--;
            if(fre[nums[i]]==0){
                fre.erase(nums[i]);
            }
            i++;
        }


        }
        return ans;
    }
};