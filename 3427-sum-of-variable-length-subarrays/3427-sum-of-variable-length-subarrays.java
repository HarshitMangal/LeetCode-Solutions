class Solution {
    public int subarraySum(int[] nums) {
        int n=nums.length;
        int [] prefix=new int[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int start=Math.max(0,i-nums[i]);
            if(start==0){
               sum+=prefix[i];
            }
            else{
                sum+=prefix[i]-prefix[start-1];
            }
        }
        return sum;
    }
}