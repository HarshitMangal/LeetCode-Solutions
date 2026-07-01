class Solution {
public:
   bool isincreasing(vector<int>&nums,int n){
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]) return false;
    }
    return true;
}
bool isdecreasing(vector<int>&nums,int n){
    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]) return false;
    }
    return true;
}
    bool isMonotonic(vector<int>& nums) {
         int n=nums.size();
         if(isincreasing(nums,n)) return true;
         if(isdecreasing(nums,n)) return true;
         return false;
    }
};