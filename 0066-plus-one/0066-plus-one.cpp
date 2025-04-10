class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool carry = false;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                carry = false;
                digits[i] += 1;
                break;
            } else {
                digits[i] = 0;
                carry = true;
            }
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};