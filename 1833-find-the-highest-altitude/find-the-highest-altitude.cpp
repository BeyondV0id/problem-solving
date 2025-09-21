class Solution {
  public:
    int largestAltitude(vector<int> &gain) {
        int maxVal = 0;
        vector<int> psum(gain.size() + 1);
        psum[0] = 0;
        for (int i = 0; i < (int)gain.size(); i++) {
            psum[i + 1] = psum[i] + gain[i];
            maxVal = max(psum[i + 1], maxVal);
        }
        return maxVal; 
    }
};