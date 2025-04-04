class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if (dividend == INT_MIN && divisor == -1) {
            result = INT_MAX;
        } else {
            result = dividend / divisor;
        }
        return result;
    }
};