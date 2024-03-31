#include <iostream>
#include <string>
#include <vector>

class Finder {
public:
    std::vector<int> findSubstrings(const std::string& s1, const std::string& s2) {
        std::vector<int> result;

        for (size_t i = 1; i <= s2.size(); ++i) {
            // Generate the current prefix from s2
            std::string prefix = s2.substr(0, i);
            // Search for this prefix in s1
            size_t found = s1.find(prefix);
            if (found != std::string::npos) {
                // If found, store the index
                result.push_back(found);
            } else {
                // If not found, store -1
                result.push_back(-1);
            }
        }

        return result;
    }
};
