class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int r1x1 = rec1[0], r1y1 = rec1[1];
        int r1x2 = rec1[2], r1y2 = rec1[3];

        int r2x1 = rec2[0], r2y1 = rec2[1];
        int r2x2 = rec2[2], r2y2 = rec2[3];

        // horizontal
        if (r1x2 <= r2x1 || r2x2 <= r1x1)
            return false;

        // vertical
        if (r1y2 <= r2y1 || r2y2 <= r1y1)
            return false;

        return true;
    }
};