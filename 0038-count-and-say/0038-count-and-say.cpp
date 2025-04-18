class Solution {
public:
    string findsameNumbers(string subNumStr) {
        string result = "";

        printf("subNumStr : %s\n", subNumStr.c_str());

        int numCnt = 0;
        int numVal = -1;

        for (int i = 0; i < subNumStr.size(); i++) {
            if (numVal == -1) {
                numVal = subNumStr[i] - '0';
                numCnt++;
            } else if (numVal != subNumStr[i] - '0') {
                result += to_string(numCnt) + to_string(numVal);
                numCnt = 1;
                numVal = subNumStr[i] - '0';
            } else {
                numCnt++;
            }
        }
        result += to_string(numCnt) + to_string(numVal);

        printf("subNumStr Result : %s\n", result.c_str());

        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        if (n != 1) {
            for (int i = 1; i < n; i++) {
                result = findsameNumbers(result);
            }
        }

        return result;
    }
};