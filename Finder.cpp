#include "Finder.h"

using namespace std;

class Finder {
public:
    vector<int> findSubstrings(string s1, string s2) {
        vector<int> result(s2.size(), -1); // Initialize results with -1
        for (size_t i = 0; i < s1.size(); ++i) {
            for (size_t j = 0; j < s2.size() && i + j < s1.size(); ++j) {
                if (s1[i + j] != s2[j]) break; // If any character doesn't match, stop this prefix
                if (result[j] == -1) result[j] = i; // Record the first match position for each prefix
            }
        }
        return result;
    }
};
