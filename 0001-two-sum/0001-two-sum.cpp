class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size() - 1; i++) {

            for (int j = i + 1; j < nums.size(); j++) {
                int val = nums[i] + nums[j];
                if (val == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
            if (result.size() > 0)
                break;
        }
        return result;
    }
};