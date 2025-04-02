// Last updated: 4/2/2025, 5:16:58 PM
/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>merged(nums1.size()+nums2.size());
        int m = 0,n = 0,k=0;
        while(m<nums1.size() && n < nums2.size()){
            if(nums1[m] <= nums2[n])
                merged[k++] = nums1[m++]; 
            else if(nums2[n] <= nums1[m]) 
                merged[k++] = nums2[n++];
        }
        while(m<nums1.size())
            merged[k++] = nums1[m++];
        while(n<nums2.size())
            merged[k++]  = nums2[n++];
        int length = merged.size();
        if(length %2!= 0)
             return merged[length/2];
        else
            return (merged[length/2]+merged[length/2-1])/2.0;
}
};
// @lc code=end

