class Solution {
public:
  bool solve(string &s,int idx,int sum,int target){
     if(idx==s.length()){
        return sum==target;
     }
      int num=0;
     for(int i=idx;i<s.length();i++){
          num=num*10+(s[i]-'0');
          if(sum+num>target) break;
          if(solve(s,i+1,sum+num,target)) return true;
     }
     return false;
  }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int sq=i*i;
            string s=to_string(sq);
            if(solve(s,0,0,i)){
                ans+=sq;
            }
        }
        return ans;
    }
};