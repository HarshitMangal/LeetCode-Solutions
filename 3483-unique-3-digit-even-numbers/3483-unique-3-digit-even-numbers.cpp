class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int n = digits.size();

        unordered_set<int> st;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    // Same index dobara use nahi kar sakte
                    if(i == j || j == k || i == k)
                        continue;

                    // Leading zero allowed nahi hai
                    if(digits[i] == 0)
                        continue;

                    // Last digit even honi chahiye
                    if(digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100 +
                              digits[j] * 10 +
                              digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};