#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    vector<int> ans;
    unordered_map<string, int> m;

    for (string s : strings) m[s]++;
    for (string s : queries) {
        ans.push_back(m[s]);
    }

    for (int i : ans) cout<<i<<" ";
    cout<<endl;

    return ans;
}


int main() {

    vector<string> strings = {};
    vector<string> queries = {};

    matchingStrings(strings, queries);
    return 0;
}

