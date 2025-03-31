class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;

        int m = nums1.size(), n = nums2.size();

        for (int i = 0; i < n; i++) {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2 == 0) {
            int val1 = nums1[nums1.size() / 2 - 1];
            int val2 = nums1[nums1.size() / 2];
            result = ((val1 + val2) / 2.0);
        } else
            result = nums1[nums1.size() / 2.0];

        return result;
    }
};