class Solution {
public:
    int rob(vector<int>& nums) {
        int result = 0;

        int n = nums.size();

        if (n == 1) {
            result = nums[0];
        } else if (n == 2) {
            result = max(nums[0], nums[1]);
        } else {
            int f = nums[0], s = max(nums[0], nums[1]);
            for (int i = 2; i < n; ++i) {
                int curr = max(s, f + nums[i]);
                f = s;
                s = curr;
            }

            result = s;
        }

        return result;
    }
};