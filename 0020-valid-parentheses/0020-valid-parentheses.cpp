class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                vec.push_back(c);
            else {
                if (vec.size() > 0) {
                    char open = vec[vec.size() - 1];
                    if ((open == '(' && c == ')') ||
                        (open == '[' && c == ']') || (open == '{' && c == '}'))
                        vec.pop_back();
                    else {
                        vec.push_back(c);
                        break;
                    }
                } else {
                    vec.push_back(c);
                    break;
                }
            }
        }

        return vec.empty();
    }
};