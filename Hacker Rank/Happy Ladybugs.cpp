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

string happyLadybugs(string b) {
    unordered_map<char, int> dict;
    dict['_']=0;
    dict[b[0]]++;

    bool flag=true;
    if (b[b.size()-1]!=b[b.size()-2]) flag=false;

    for (int i=1 ; i<b.size() ; i++) {
        dict[b[i]]++;
        if (i<b.size()-1 && b[i]!=b[i-1] && b[i]!=b[i+1]) flag=false;
    }
    if (flag && b.size()-dict['_']>1) return "YES";
    if (dict.size()==2 && b.size()-dict['_']>1) return "YES";
    if (dict.size()==1) return "YES";


    if (dict['_']<1) return "NO";
    else {
        unordered_map<char, int>::iterator iter;
        for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
            if (iter->first!='_' && iter->second<2) return "NO";
        }
    }
    return "YES";
}

int main() {

    string b="P______";
    cout<<happyLadybugs(b);

    return 0;
}


