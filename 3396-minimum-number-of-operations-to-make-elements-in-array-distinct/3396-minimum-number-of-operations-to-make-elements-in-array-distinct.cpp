class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;

        while (!nums.empty()) {
            set<int> setNums(nums.begin(), nums.end());
            if (nums.size() == setNums.size())
                break;

            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            result++;
        }

        return result;
    }
};