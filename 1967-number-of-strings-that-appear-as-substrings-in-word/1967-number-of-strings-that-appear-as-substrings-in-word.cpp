class Solution {
public:
    int numOfStrings(vector<string>& s, string word) {
        int n=s.size();
         int count=0;
         for(auto it:s){
           if(word.find(it)!=string ::npos){
            count++;
           }

         }
         return count;

    
    }
};