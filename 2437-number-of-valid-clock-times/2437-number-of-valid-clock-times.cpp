class Solution {
public:
    int countTime(string time) {

        int cnt = 0;

        for (int h = 0; h < 24; h++) {
            for (int m = 0; m < 60; m++) {

                string cur = "";

                if (h < 10)
                    cur += '0';
                cur += to_string(h);

                cur += ":";

                if (m < 10)
                    cur += '0';
                cur += to_string(m);

                bool ok = true;

                for (int i = 0; i < 5; i++) {
                    if (time[i] != '?' && time[i] != cur[i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok)
                    cnt++;
            }
        }

        return cnt;
    }
};