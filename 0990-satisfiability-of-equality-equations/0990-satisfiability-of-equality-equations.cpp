class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionset(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        // Union by rank
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        // Initializing each variable's parent to itself
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Step 1: Union all variables which are equal
        for (string &s : equations) {
            if (s[1] == '=') {
                unionset(s[0] - 'a', s[3] - 'a');
            }
        }

        // Step 2: Check if any "!=" equation contradicts
        for (string &s : equations) {
            if (s[1] == '!') {
                int x = find(s[0] - 'a');
                int y = find(s[3] - 'a');
                if (x == y) return false;
            }
        }

        return true;
    }
};