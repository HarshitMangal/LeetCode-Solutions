class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n=strs.length;
        Arrays.sort(strs);
        String temp="";
        String start=strs[0];
        String end=strs[n-1];
        for(int i=0;i<Math.min(start.length(),end.length());i++){
            if(start.charAt(i)==end.charAt(i)){
                temp+=start.charAt(i);
            }
            else break;
        }

      return temp;
        
    }
}