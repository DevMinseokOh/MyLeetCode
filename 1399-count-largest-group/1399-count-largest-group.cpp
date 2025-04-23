class Solution {
public:
    int getSumValue(int n) {
        int res = 0;
        string str = to_string(n);

        for (int i = 0; i < str.size(); i++) {
            res += str[i] - '0';
        }

        return res;
    }
    int countLargestGroup(int n) {
        int res = 0;
        int resNum = 0;

        map<int, int> mp;

        for (int i = 1; i <= n; i++) {
            int sumValue = getSumValue(i);
            auto it = mp.find(sumValue);

            if (it == mp.end()) {
                mp.insert(std::pair<int, int>(sumValue, 1));
            } else {
                mp[sumValue]++;
            }
        }

        for (auto& it : mp) {
            if (res < it.second) {
                res = it.second;
                resNum = 1;
            } else if (res == it.second) {
                resNum++;
            }
        }

        return resNum;
    }
};