class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
         int n=transactions.size();
         vector<string>name(n);
         vector<string>city(n);
         vector<int>time(n);
         vector<int>amount(n);
         for(int i=0;i<n;i++){
              string s=transactions[i];
              vector<string>temp;
              string curr="";
             for(char c:s){
                if(c==','){
                     temp.push_back(curr);
                     curr="";
                }
                else{
                    curr+=c;
                }
             }
                temp.push_back(curr);
                name[i]=temp[0];
                time[i]=stoi(temp[1]);
                amount[i]=stoi(temp[2]);
                city[i]=temp[3];
             }
                vector<string> ans;

        for (int i = 0; i < n; i++) {

            bool invalid = false;

            // Condition 1
            if (amount[i] > 1000)
                invalid = true;

            // Condition 2
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                if (name[i] == name[j] &&
                    city[i] != city[j] &&
                    abs(time[i] - time[j]) <= 60) {

                    invalid = true;
                    break;
                }
            }

            if (invalid)
                ans.push_back(transactions[i]);
        }

        return ans;

    }   
};