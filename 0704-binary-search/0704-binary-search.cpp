class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int checkValue = nums[mid];
            if (checkValue == target) {
                result = mid;
                break;
            } else if (checkValue < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;
    }
};