class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
           int n = bits.size();
        int i = 0;
        
        while(i < n - 1) { // last element se pehle tak chalo
            if(bits[i] == 1) {
                i += 2; // two-bit char
            } else {
                i += 1; // one-bit char
            }
        }
        
        return i == n - 1; // agar yahi par khatam hua to true
    }
};