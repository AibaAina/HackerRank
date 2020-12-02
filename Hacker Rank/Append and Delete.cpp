#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

string appendAndDelete(string s, string t, int k) {

    int x=s.size()-t.size();
    if (abs(x)>k) return "No";

    if (s[0]!=t[0]) {
        if (k<s.size()) return "No";
        else k-=s.size();

        if (k>=t.size()) return "Yes";
        else return "No";
    }

    for (int i=0 ; i<t.size() ; ) {
        if (s[i]!=t[i]) {
            k--;
            if (k<0) return "No";

            if (s.size()>i) s.pop_back();
            else {
                s.push_back(t[i]);
                i++;
            }
        }
        else {
            i++;
        }
    }

    while (s.size()>t.size()) {
        s.pop_back();
        k--;
    }

    if (k%2==0) return "Yes";
    else if (k%2==1 && k>=s.size()*2) return "Yes";
    else return "No";
}

int main() {

    string s = "y";
    string t = "yu";
    int k=9;

    cout<<appendAndDelete(s,t,k)<<endl;
    return 0;
}

