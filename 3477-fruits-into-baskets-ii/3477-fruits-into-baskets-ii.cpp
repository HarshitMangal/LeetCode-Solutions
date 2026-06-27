class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = fruits.size();
        vector<int> vis(n, 0);

        int i = 0;
        int count = 0;

        while (i < n) {

            int j = 0;

            while (j < n) {

                if (!vis[j] && baskets[j] >= fruits[i]) {
                    vis[j] = 1;
                    count++;
                    break;
                }

                j++;
            }

            i++;
        }

        return n - count;
    }
};