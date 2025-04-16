// Last updated: 4/16/2025, 4:41:33 PM
class Solution {
public:
    int captureForts(std::vector<int>& forts) {
        int maxDistance = 0;
        int count;
        int left = 0, n = forts.size();

        while (left < n) {
            while (left < n && forts[left] == 0)
                left++;

            int right = left + 1;

            while (right < n && forts[right] == 0)
                right++;
            if (right < n && forts[left] + forts[right] == 0) {
                bool valid_path = true;
                for (int i = left + 1; i < right; i++) {
                    if (forts[i] != 0) {
                        valid_path = false;
                        break;
                    }
                }
                if (valid_path) {
                    maxDistance = max(maxDistance, right - left - 1);
                }
            }

            left = right;
        }

        return maxDistance;
    }
};