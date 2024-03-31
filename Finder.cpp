#include "Finder.h"

std::vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    std::vector<int> positions;
    for (size_t length = 1; length <= s2.size(); ++length) {
        std::string prefix = s2.substr(0, length);
        bool found = false;
        for (size_t i = 0; i <= s1.size() - prefix.size(); ++i) {
            if (s1.substr(i, prefix.size()) == prefix) {
                positions.push_back(i);
                found = true;
                break;
            }
        }
        if (!found) {
            positions.push_back(-1);
        }
    }
    return positions;
}
