class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;
        int idx = haystack.find(needle);
        if (idx != string::npos)
            result = idx;
        return result;
        /*int result = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                string needleSubStr = haystack.substr(i, needle.size());

                if (needleSubStr == needle) {
                    result = i;
                    break;
                }
            }
        }

        return result;*/
    }
};