class Solution {
    boolean solve(char[][]mat,String s,int i,int j,int idx,boolean[][]visited){
       int n=mat.length;
       int m=mat[0].length;
       if(idx==s.length()) return true;
       if(i<0||i>=n||j<0||j>=m||mat[i][j]!=s.charAt(idx)||visited[i][j]==true) return false;
       visited[i][j]=true;
       boolean ans=(solve(mat,s,i+1,j,idx+1,visited)||
                    solve(mat,s,i-1,j,idx+1,visited)||
                    solve(mat,s,i,j+1,idx+1,visited)||
                    solve(mat,s,i,j-1,idx+1,visited));
                
                visited[i][j]=false;
                return ans;



    }
    public boolean exist(char[][] mat, String s) {
          int n=mat.length;
          int m=mat[0].length;
          boolean[][] visited=new boolean[n][m];
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==s.charAt(0)){
                    if(solve(mat,s,i,j,0,visited)==true){
                        return true;
                    }
                }
            }
          }
          return false;
    }
}