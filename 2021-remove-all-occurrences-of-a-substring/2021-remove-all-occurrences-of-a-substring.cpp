class Solution {
public:
    string removeOccurrences(string s, string part) {
        std::size_t found = s.find(part);
        while (found != string::npos) {
            printf("%s - %s = ", s.c_str(), part.c_str());
            s.erase(found, part.size());
            found = s.find(part);
            printf("%s\n", s.c_str());
        }
        return s;
    }
};