class Solution {
public:
    bool isSymmetric(int n) {
        bool res = false;
        string str = to_string(n);
        int len = str.size();
        int half = str.size() / 2;

        if (len % 2 == 0) {
            int check = 0;
            for (int i = 0; i < half; i++) {
                check += str[i] - '0';
                check -= str[i + half] - '0';
            }
            res = (check == 0);
        }
        return res;
    }

    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            int digit = static_cast<int>(log10(i)) + 1;
            if (digit % 2 == 0 && isSymmetric(i))
                ++res;
        }

        return res;
    }
};