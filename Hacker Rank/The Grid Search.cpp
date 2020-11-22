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

string gridSearch(vector<string> g, vector<string> p) {

    string ans="NO";

    int row_g = g.size(), col_g = g[0].size();
    int row_p = p.size(), col_p = p[0].size();
    
    for (int i=0 ; i<row_g-row_p+1 ; i++) {
        for (int j=0 ; j<col_g-col_p+1 ; j++) {
            // find
            if (g[i].substr(j, col_p) == p[0]) {
                for (int k=1 ; k<row_p ; k++) {
                    if (g[i+k].substr(j, col_p) != p[k]) {
                        ans="NO";
                        break;
                    }
                    else ans="YES";
                }
                if (ans=="YES") return ans;
            }
        }
    }

    return ans;
}

int main() {

    vector<string> G;
    vector<string> P;
    cout<<gridSearch(G,P);

    return 0;
}


