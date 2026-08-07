class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {

        vector<int> reach(time + 1, 0);

        // reach[start] = farthest end
        for (auto &clip : clips) {
            int start = clip[0];
            if (start > time) continue;

            int end = min(clip[1], time);
            reach[start] = max(reach[start], end);
        }

        int maxi = 0;
        int currEnd = 0;
        int clipsUsed = 0;

        for (int i = 0; i < time; i++) {

            if (i > maxi)
                return -1;

            maxi = max(maxi, reach[i]);

            if (i == currEnd) {
                clipsUsed++;
                currEnd = maxi;
            }
        }

        return (currEnd >= time) ? clipsUsed : -1;
    }
};