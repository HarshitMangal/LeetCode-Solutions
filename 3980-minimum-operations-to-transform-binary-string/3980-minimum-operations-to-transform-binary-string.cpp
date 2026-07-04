class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        string cur = s1;
        int ops = 0;
        
        for (int i = 0; i < n; i++) {
            if (cur[i] == s2[i]) continue;   // already sahi hai, kuch mat karo
            
            if (cur[i] == '0') {
                // 0 -> 1 chahiye, seedha Op1 laga do
                cur[i] = '1';
                ops++;
            } else {
                // 1 -> 0 chahiye, neighbor ke saath pair karke Op2 se clear karo
                
                if (i + 1 < n) {
                    // pehle try karo agle (i+1) ke saath jodne ka
                    if (cur[i+1] == '0') {
                        cur[i+1] = '1';   // neighbor ko taiyar karo
                        ops++;
                    }
                    cur[i] = '0';
                    cur[i+1] = '0';       // dono clear
                    ops++;
                } else if (i - 1 >= 0) {
                    // yeh last index hai, peeche wale (i-1) se jodo
                    if (cur[i-1] == '0') {
                        cur[i-1] = '1';
                        ops++;
                    }
                    cur[i-1] = '0';
                    cur[i] = '0';
                    ops++;
                    // agar i-1 ka target '1' tha, wapas set karo
                    if (s2[i-1] == '1') {
                        cur[i-1] = '1';
                        ops++;
                    }
                } else {
                    return -1;  // n==1, akela '1' kabhi clear nahi ho sakta
                }
            }
        }
        
        return (cur == s2) ? ops : -1;
    }
};