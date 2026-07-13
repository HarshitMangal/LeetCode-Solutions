class Solution {
public:
  int generate(int start,int len){
    int num=0;

     for(int i=0;i<len;i++){
        num=num*10+(start+i);
     }
     return num;
  }
    vector<int> sequentialDigits(int low, int high) {
          vector<int>ans;
          for(int len=2;len<=9;len++){
            for(int start=1;start+len-1<=9;start++){
                int num=generate(start,len);
                if(num>=low&&num<=high){
                    ans.push_back(num);
                }
            }
          }
          return ans;
    }
};