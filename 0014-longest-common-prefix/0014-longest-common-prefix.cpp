class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        int n = INT_MAX;
        for (const string& str : strs) {
            if (n > str.size()) {
                n = str.size();
            }
        }

        for (int i = 0; i < n; i++) {
            char c = strs[0][i];
            bool canAdd = true;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c)
                    canAdd = false;
            }
            if (canAdd)
                result += c;
            else
                break;
        }

        return result;
    }
};