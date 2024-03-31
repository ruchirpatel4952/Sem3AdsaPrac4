#include "Finder.h"
using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result(s2.size(), -1); // Initialize with -1
    size_t lastPos = string::npos;

    // Search for each prefix from the end to the beginning
    for (size_t len = s2.size(); len > 0; --len) {
        string prefix = s2.substr(0, len);
        size_t found = s1.rfind(prefix); // Use rfind for reverse search
        if (found != string::npos) {
            lastPos = found; // Update last found position
            result[len - 1] = found; // Correct position for the prefix
            // Update all previous indexes if they are -1
            for (int i = len - 2; i >= 0 && result[i] == -1; --i) {
                result[i] = found;
            }
        }
    }
    return result;
}
