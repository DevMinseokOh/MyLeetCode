class Solution {
public:
    int reverse(int x) {
        long result = 0;
        string s = to_string(x);
        bool negative = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (!negative && c == '-') {
                negative = true;
                result *= -1;
            } else {
                result *= 10;
                result += c - '0';

                if (result > INT_MAX) {
                    result = 0;
                    break;
                } else if (result < INT_MIN) {
                    result = 0;
                    break;
                }
            }
        }

        return result;
    }
};