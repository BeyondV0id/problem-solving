class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for (auto num : nums) {
            st.insert(num);
        }

        int maxSeq = 0;

        for (auto it : st) {
            if (!st.count(it - 1)) {
                int seq = 1;
                int cur = it;

                while (st.count(cur + 1)) {
                    seq++;
                    cur++;
                }

                maxSeq = max(maxSeq, seq);
            }
        }
        return maxSeq;
    }
};