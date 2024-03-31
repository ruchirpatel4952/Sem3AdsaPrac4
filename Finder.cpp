#include "Finder.h" // Include the header file, do not redefine the class in this file.

// Ensure the method signature exactly matches the declaration in Finder.h
std::vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    std::vector<int> result(s2.size(), -1); // Initialize with -1 indicating not found

    for (size_t start = 0; start < s1.size(); ++start) {
        for (size_t len = 1; len <= s2.size(); ++len) {
            if (start + len > s1.size()) break; // Avoid overflow

            std::string prefix = s2.substr(0, len);
            std::string segment = s1.substr(start, len);

            if (prefix == segment && result[len - 1] == -1) {
                result[len - 1] = start; // Record the start position for this prefix
            }
        }
    }
    return result;
}
