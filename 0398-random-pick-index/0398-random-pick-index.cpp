class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int curr=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                count++;
            if(rand()%count==0){
                curr=i;
            }
            }
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */