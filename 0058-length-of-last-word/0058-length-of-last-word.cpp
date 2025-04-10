class Solution {
public:
    int lengthOfLastWord(string s) {
        string lastStr = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (lastStr.size() == 0)
                    continue;
                else
                    break;
            } else {
                lastStr += s[i];
            }
        }

        return lastStr.size();
    }
};