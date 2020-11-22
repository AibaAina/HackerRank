#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

string superReducedString(string s) {

    string ans="";

    stack<char> st;
    for (int i=0 ; i<s.size() ; i++) {
        if (st.empty() || st.top()!=s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }

    if (st.empty()) return "Empty String";

    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    string s = "aaabccddd";
    
    cout<<superReducedString(s);

    return 0;
}


