class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        string start = "0000";
        if(dead.count(start)) return -1;
        if(start == target) return 0;

        queue<pair<string,int>> q;
        q.push({start, 0});
        visited.insert(start);

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            string temp = front.first;
            int moves = front.second;

            if(temp == target) return moves;

            for(int i = 0; i < 4; i++) {

                // forward
                string next = temp;
                next[i] = ((next[i] - '0') + 1) % 10 + '0';
                if(!dead.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }

                // backward
                string pre = temp;
                pre[i] = ((pre[i] - '0') +9) % 10 + '0';
                if(!dead.count(pre) && !visited.count(pre)) {
                    visited.insert(pre);
                    q.push({pre, moves + 1});
                }
            }
        }
        return -1;
    }
};