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

string encryption(string s) {

    int row = sqrt(s.size());
    int col = row+1;
    if (row*row==s.size()) col=row;
    else if (row*col<s.size()) row++;

    string ans = "";

    for (int i=0 ; i<col ; i++) {
        for (int j=0 ; j<row ; j++) {
            int pos = j*col+i;
            // cout<<pos<<endl;
            if (pos>s.size()-1) break;
            ans+=s[pos];
        }
        ans+=" ";
    }
    return ans;
}

int main() {

    string s1 = "haveaniceday";
    string s2 = "chillout";

    cout<<encryption(s1);

    return 0;
}


