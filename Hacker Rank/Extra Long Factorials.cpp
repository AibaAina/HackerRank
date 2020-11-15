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

vector<vector<int>> dict;

void ans(int n) {
    for (int i=dict[n].size()-1 ; i>=0 ; i--)
        cout<<dict[n][i];
    cout<<endl;
}

void extraLongFactorials(int n) {

    for (int i=1 ; i<=n ; i++) {
        // dict have the value
        if (i<=dict.size()-1) 
            continue;
        // dict need to add
        else {
            vector<int> temp = dict[i-1];
            int pass=0;
            for (int j=0 ; j<temp.size() ; j++) {
                int cal=temp[j]*i;
                temp[j] = (cal%10 + pass)%10;
                pass = cal/10 + (cal%10 + pass)/10;
            }
            if (pass>0) {
                string s=to_string(pass);
                for (int i=s.size()-1 ; i>=0 ; i--)
                    temp.push_back(s[i]-'0');
            }
            dict.push_back(temp);
        }
    }
    ans(n);
}

int main() {

    int n=25;

    dict.push_back({0});
    dict.push_back({1});
    dict.push_back({2});
    dict.push_back({6});
    dict.push_back({4,2});

    extraLongFactorials(n);
    return 0;
}

