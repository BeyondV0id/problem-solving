class Solution {
private:
    void merge(vector<vector<int>>& intervals, int left, int mid, int right) {
        int i = left, j = mid + 1;
        vector<vector<int>> temp;

        while (i <= mid && j <= right) {
            if (intervals[i][1] <= intervals[j][1]) {
                temp.push_back(intervals[i++]);
            } else {
                temp.push_back(intervals[j++]);
            }
        }

        while (i <= mid) temp.push_back(intervals[i++]);
        while (j <= right) temp.push_back(intervals[j++]);

        for (int k = 0; k < temp.size(); ++k) {
            intervals[left + k] = temp[k];
        }
    }

    void mergeSort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(intervals, left, mid);
        mergeSort(intervals, mid + 1, right);
        merge(intervals, left, mid, right);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        mergeSort(intervals, 0, intervals.size() - 1);

        int count = 1;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            if (prev[1] <= intervals[i][0]) {
                count++;
                prev = intervals[i];
            }
        }

        return intervals.size() - count;
    }
};
