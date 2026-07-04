class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
           vector<int>ans;
           while(label!=0){
            ans.push_back(label);
            int start=1;
            int end=1;
            while(end<label){
                start=end+1;
                end=end*2+1;
            }
             label=(start+end-label)/2;
           }
           sort(ans.begin(),ans.end());
           return ans;

    }
};