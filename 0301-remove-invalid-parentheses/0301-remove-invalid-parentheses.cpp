class Solution {
public:
 bool isvalid(string &s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
               vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
         q.push(s);
        visited.insert(s);
        bool found=false;

        while (!q.empty()) {
            string temp = q.front(); q.pop();
            
            if(isvalid(temp)){
                ans.push_back(temp);
                found=true;
            }
             if(found==true) continue;
            //generate new string
                 for (int i = 0; i < temp.length(); i++) {
                      if(temp[i]!='('&&temp[i]!=')') continue;
              string next = temp.substr(0, i) + temp.substr(i + 1);
                if (visited.find(next) == visited.end()) {
                    q.push(next);
                    visited.insert(next);

            }
          }
        }
           return ans;

    }
};