#include "Finder.h"

using namespace std;

class Finder {
public:
    vector<int> findSubstrings(const string& s1, const string& s2) {
        vector<int> results;
        for (size_t prefixLength = 1; prefixLength <= s2.length(); ++prefixLength) {
            string prefix = s2.substr(0, prefixLength);
            vector<int> lps = buildLPSArray(prefix);
            int result = KMPSearch(s1, prefix, lps);
            results.push_back(result);
        }
        return results;
    }

private:
    vector<int> buildLPSArray(const string& pattern) {
        vector<int> lps(pattern.size(), 0);
        int length = 0;
        int i = 1;
        while (i < pattern.size()) {
            if (pattern[i] == pattern[length]) {
                lps[i++] = ++length;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    int KMPSearch(const string& text, const string& pattern, const vector<int>& lps) {
        int i = 0; // index for text
        int j = 0; // index for pattern
        while (i < text.size()) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == pattern.size()) {
                return i - j; // Found pattern at index i - j
                j = lps[j - 1];
            } else if (i < text.size() && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }
        return -1; // Pattern not found
    }
};
