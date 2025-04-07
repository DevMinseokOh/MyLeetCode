class Solution {
public:
    int fib(int n) {
        int result = 0;
        if (n <= 1)
            result = n;
        else {
            int f = 0, s = 1;
            for (int i = 2; i <= n; i++) {
                int newValue = f + s;
                f = s;
                s = newValue;
            }
            result = s;
        }
        return result;
    }
};