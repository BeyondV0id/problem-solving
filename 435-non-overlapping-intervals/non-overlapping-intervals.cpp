class Solution {
private:
    void merge(vector<vector<int>>& intervals, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<vector<int>> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = intervals[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = intervals[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i][1] <= rightArr[j][1]) {
                intervals[k] = leftArr[i];
                i++;
            } else {
                intervals[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            intervals[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            intervals[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<vector<int>>& intervals, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(intervals, left, mid);
            mergeSort(intervals, mid + 1, right);
            merge(intervals, left, mid, right);
        }
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;


        mergeSort(intervals, 0, intervals.size() - 1);

        int cnt = 1;  
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> cur = intervals[i];
            if (prev[1] <= cur[0]) {  
                cnt++;
                prev = cur;
            }
        }

        return intervals.size() - cnt;
    }
};

