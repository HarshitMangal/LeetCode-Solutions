class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr=startPos[0];
        int sc=startPos[1];
        int hr=homePos[0];
        int hc=homePos[1];
        long long cost = 0;

        // move rows
        if (sr < hr) {
            for (int r = sr + 1; r <= hr; r++) cost += rowCosts[r];
        } else {
            for (int r = sr - 1; r >= hr; r--) cost += rowCosts[r];
        }

        // move cols
        if (sc < hc) {
            for (int c = sc + 1; c <= hc; c++) cost += colCosts[c];
        } else {
            for (int c = sc - 1; c >= hc; c--) cost += colCosts[c];
        }

        return cost;
    
    }
};