#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t pos = s1.find(s2);

    if (pos != string::npos) {
        for (size_t i = 0; i < s2.length(); ++i) {
            result.push_back(pos); 
        }
    } else {
        for (size_t i = 0; i < s2.length(); ++i) {
            result.push_back(-1);
        }
    }

    return result;
}
