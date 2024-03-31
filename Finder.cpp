#include "Finder.h"

using namespace std;

class Finder {
public:
    vector<int> findSubstrings(string s1, string s2);
};

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result(s2.size(), -1); // Initialize with -1 indicating not found

    for (size_t start = 0; start < s1.size(); ++start) {
        for (size_t len = 1; len <= s2.size(); ++len) {
            if (start + len > s1.size()) break; // Avoid overflow

            string prefix = s2.substr(0, len);
            string segment = s1.substr(start, len);

            if (prefix == segment && result[len - 1] == -1) {
                result[len - 1] = start; // Record the start position for this prefix
            }
        }
    }
    return result;
}
