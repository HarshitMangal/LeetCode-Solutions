class Solution {
public:
    string convert(string s, int num) {
        int n = s.length();

        if(num == 1) return s;

        vector<string> mp(num);

        bool lefttoright = false;
        int index = 0;

        for(auto it : s) {

            if(index == 0 || index == num - 1) {
                lefttoright = !lefttoright;
            }

            mp[index].push_back(it);

            if(lefttoright == true) {
                index++;
            }
            else {
                index--;
            }
        }

        string temp = "";

        for(auto it : mp) {
            temp += it;
        }

        return temp;
    }
};