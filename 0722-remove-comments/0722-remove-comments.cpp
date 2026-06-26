class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
          vector<string>ans;
          string curr="";
           bool block=false;
        for(string line : source){
 
         for(int i = 0; i < line.size(); i++){
            if(block==false){
                  if(i + 1 < line.size() &&
                       line[i] == '/' &&
                       line[i + 1] == '/')
                    {
                        break;
                    }
                    else if(i + 1 < line.size() &&
                            line[i] == '/' &&
                            line[i + 1] == '*')
                    {
                        block = true;
                        i++;
                    }
                else{
                    curr+=line[i];
                }
            }
            else{
                  if(i + 1 < line.size() &&
                       line[i] == '*' &&
                       line[i + 1] == '/')
                    {
                        block = false;
                        i++;
                    }
            }

        }
         if(!block && !curr.empty())
            {
                ans.push_back(curr);
                curr = "";
            }

     }
     return ans;
    }
};