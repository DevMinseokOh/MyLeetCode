class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        if (s.size() > 1 && numRows != 1) {
            vector<string> alphabet(numRows);
            bool down = true;
            int row = 0;
            for (char c : s) {
                alphabet[row] += c;

                if (down) {
                    if (row == numRows - 1)
                        down = !down;
                } else {
                    if (row == 0) {
                        down = !down;
                    }
                }

                row = (down) ? row + 1 : row - 1;
            }

            for (const string& str : alphabet) {
                result += str;
            }
        } else {
            result = s;
        }

        return result;
    }
};