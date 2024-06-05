/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        nums1.push_back((int) 1e9);
        nums2.push_back((int) 1e9);
        if (n < m) swap(nums1, nums2), swap(n, m);
        if (m == 0) {
            return n & 1 ? nums1[n / 2] : (nums1[n / 2] + nums1[n / 2 - 1]) / 2.0;
        }
        int l = 0, r = n + 1;
        while (1) {
            int md = (l + r) >> 1;
            int rest = ((n + m + 1) >> 1) - md;
            if (rest < 0) r = md;
            else if (rest > m) l = md;
            else {
                if (md == 0) { 
                    if (nums2[rest - 1] > nums1[0]) l = md;
                    else return (n + m) & 1 ? nums2[rest - 1] : (nums2[rest - 1] + min(nums2[rest], nums1[0])) / 2.0;
                } else if (rest == 0) {
                    if (nums1[md - 1] > nums2[0]) r = md;
                    else return (n + m) & 1 ? nums1[md - 1] : (nums1[md - 1] + min(nums1[md], nums2[0])) / 2.0;
                } else {
                    if (rest < m && nums1[md - 1] > nums2[rest]) r = md;
                    else if (md < n && nums1[md] < nums2[rest - 1]) l = md;
                    else return (n + m) & 1 ? max(nums1[md - 1], nums2[rest - 1]) : 
                        (max(nums1[md - 1], nums2[rest - 1]) + min(nums1[md], nums2[rest])) / 2.0;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

