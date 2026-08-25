class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int x:nums){
            mp.put(x,mp.getOrDefault(x,0)+1);
        }    
        for(int i=k;;i+=k){
            if(!mp.containsKey(i)){
                return i;
            }
        }
      
    }
}