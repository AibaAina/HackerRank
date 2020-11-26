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

void separateNumbers(string s) {

    string a,t;
    for (int len=1 ; len<=s.size()/2 ; len++) {
        a = t = s.substr(0, len);
        // cout<<a<<endl;
        for (int i=1 ; t.size()<s.size() ; i++) {
            t+=to_string(stoll(a)+i);
        }
        // cout<<t<<" "<<s<<endl;
        if (s==t) {
            cout<<"YES "<<a<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main() {

    string s = "11111111111111111111111111111111";
    separateNumbers(s);
    
    return 0;
}

