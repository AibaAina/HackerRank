#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {

    vector<string> ans;

    unordered_map<char, int> dict;

    int count=1, i;
    for (i=1 ; i<s.size() ; i++) {
        if (s[i]==s[i-1]) count++;
        else {
            dict[s[i-1]] = max(dict[s[i-1]], count);
            count=1;
        }
    }
    if (count==1) dict[s[i-1]] = max(dict[s[i-1]], 1);
    else dict[s[i-1]] = max(dict[s[i-1]], count);

    unordered_map<char, int>::iterator iter;
    for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    for (int i: queries) {
        bool yes=false;
        unordered_map<char, int>::iterator iter;
        for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
            if (i%((iter->first-'a')+1)==0 && i/((iter->first-'a')+1)<=iter->second) {
                ans.push_back("Yes");
                yes=true;
                break;
            }
        }
        if (!yes) ans.push_back("No");
    }

    return ans;
}

int main() {

    string s = "aaabbbbcccdddccbb";
    vector<int> queries= {9, 7, 8, 12, 5};
    weightedUniformStrings(s, queries);
    
    return 0;
}

