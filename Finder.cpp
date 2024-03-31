#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    vector<int> result(s2.size(), -1); 
    for (size_t i = 0; i < s1.size(); ++i) {
        for (size_t j = 0; j < s2.size() && i + j < s1.size(); ++j) {
            if (s1[i + j] != s2[j]) break; 
            if (result[j] == -1) result[j] = i; 
        }
    }
    return result;
}
