#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;

    for (size_t i = 1; i <= s2.size(); i++) {
        string prefix = s2.substr(0, i);
        size_t found = s1.find(prefix);
        if (found != string::npos) {
            result.push_back(found);
        } else {
            for (size_t j = i; j <= s2.size(); j++) {
                result.push_back(-1);
            }
            break;
        }
    }
    return result;
}
