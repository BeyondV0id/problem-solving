// Last updated: 4/23/2025, 6:32:10 AM
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        outPlaceMerge(nums, low, mid, high);
    }

    void outPlaceMerge(vector<int>& nums, int low, int mid, int high) {
        if (low >= high) return;

        int l = low, r = mid + 1, k = 0;
        int size = high - low + 1;
        vector<int> sorted(size, 0);

        while (l <= mid && r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        
        while (l <= mid)
            sorted[k++] = nums[l++];
        
        while (r <= high)
            sorted[k++] = nums[r++];
        
        for (k = 0; k < size; k++)
            nums[low + k] = sorted[k];
    }
};
