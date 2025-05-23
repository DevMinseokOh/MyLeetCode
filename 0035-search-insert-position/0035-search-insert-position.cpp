class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = -1;

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                result = mid;
                break;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        if (result == -1)
            result = l;

        return result;
    }
};