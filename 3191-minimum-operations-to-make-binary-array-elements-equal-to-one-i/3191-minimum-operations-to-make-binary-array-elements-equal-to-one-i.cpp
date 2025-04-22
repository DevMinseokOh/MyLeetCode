class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                result++;
            }
        }
        set<int> mapNums;
        mapNums.insert(nums.begin(), nums.end());

        return (mapNums.size() == 1) ? result : -1;
    }
};