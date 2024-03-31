#include "Finder.h"

std::vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    std::vector<int> result;

    for (size_t i = 1; i <= s2.length(); ++i) {
        std::string prefix = s2.substr(0, i);
        size_t found = s1.find(prefix);
        if (found != std::string::npos) {
            result.push_back(found);
        } else {
            result.push_back(-1);
        }
    }

    return result;
}
