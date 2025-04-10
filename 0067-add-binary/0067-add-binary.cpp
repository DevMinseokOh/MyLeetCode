class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        int aIdx = a.size() - 1;
        int bIdx = b.size() - 1;

        bool carry = false;
        while (aIdx >= 0 || bIdx >= 0) {

            int calc = (aIdx >= 0 ? a[aIdx] - '0' : 0) +
                        (bIdx >= 0 ? b[bIdx] - '0' : 0) +
                        (carry ? 1 : 0);

            if (calc <= 1) {
                result = to_string(calc) + result;
                carry = false;
            } else {
                result = to_string(calc - 2) + result;
                carry = true;
            }

            aIdx--;
            bIdx--;
        }
        if (carry)
            result = "1" + result;

        return result;
    }
};