class Solution {
public:
    string digitSum(string s, int k) {

        vector<int>ans;
        int num=0;
        while(s.size()>k){
            for(int i=0;i<s.size();i++){
                num=0;
                for(int j=0;j<k;j++){
                    if(i<s.size())
                    num+=s[i]-'0';
                    i++;
                }
                i--;
                ans.push_back(num);
            }
            s.clear(); //clear previous string
            for(int i=0;i<ans.size();i++){
                s+=to_string(ans[i]);
            }
            ans.clear();
        }
        return s;
        
    }
};