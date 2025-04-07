class Solution {
public:
    int climbStairs(int n) {
        int result = 0;
        if (n <= 2)
            result = n;
        else {
            int first = 1, second = 2;
            for (int i = 3; i <= n; i++) {
                int cur = first + second;
                first = second;
                second = cur;
            }
            result = second;
        }
        return result;
    }
};