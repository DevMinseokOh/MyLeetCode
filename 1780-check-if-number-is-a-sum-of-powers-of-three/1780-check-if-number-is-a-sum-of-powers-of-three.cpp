class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i = 1;
        int last = -1;
        while (n > 0) {
            if (n >= pow(3, i)) {
                i++;
            } else {
                /*printf("%d - %.0f = %.0f\n", n, pow(3, i - 1),
                       n - pow(3, i - 1));*/
                if (last != i - 1) {
                    last = i - 1;
                    printf("%d ", last);
                    n -= pow(3, last);
                    i = 1;
                } else {
                    n = -1;
                    break;
                }
            }
        }

        return (n == 0);
    }
};