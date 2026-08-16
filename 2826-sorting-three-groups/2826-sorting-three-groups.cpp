class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int b=0;
        int c=0;
        for(auto it:nums){
            if(it==1){
                a++; //a pe katam hone hone val ma subsequnce
            }
            else if(it==2){
                b=max({a,b})+1; //samaja me arah he b pe khatam hone vala max subsequnce
            }
            else{
                c=max({a,b,c})+1;
            }
        }
        int keep=max({a,b,c});
        return n-keep;
    }
};