class Solution {
public:
    int tribonacci(int n) {
        int result = 0;

        if (n <= 1)
            result = n;
        else {
            int f = 0, s = 1, t = 1;

            for (int i = 3; i <= n; i++) {
                int cur = f + s + t;
                f = s;
                s = t;
                t = cur;
            }
            result = t;
        }

        return result;
    }
};