#include "Finder.h"

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t lastFound = 0; 
    bool foundAllPrevious = true; 
    for (size_t i = 1; i <= s2.size() && foundAllPrevious; ++i) {
        string prefix = s2.substr(0, i);
        size_t foundPos = s1.find(prefix, lastFound);
        
        if (foundPos != string::npos) {
            result.push_back(foundPos);
            lastFound = foundPos + 1;
        } else {
            foundAllPrevious = false; 
            result.push_back(-1);
        }
    }
    return result;
}
