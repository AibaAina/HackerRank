#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int formingMagicSquare(vector<vector<int>> s) {

    vector<int> ans;

    vector<vector<vector<int>>> pre = { 
        {{8,1,6}, {3,5,7}, {4,9,2}},
        {{4,3,8}, {9,5,1}, {2,7,6}},
        {{2,9,4}, {7,5,3}, {6,1,8}},
        {{6,7,2}, {1,5,9}, {8,3,4}},
        {{6,1,8}, {7,5,3}, {2,9,4}},
        {{8,3,4}, {1,5,9}, {6,7,2}},
        {{4,9,2}, {3,5,7}, {8,1,6}},
        {{2,7,6}, {9,5,1}, {4,3,8}}
    };

    for (vector<vector<int>> p : pre) {
        int cost=0;
        for (int i=0 ; i<3 ; i++) {
            for (int j=0 ; j<3 ; j++) {
                if (s[i][j] != p[i][j]) 
                    cost += abs(s[i][j]-p[i][j]);
            }
        }
        ans.push_back(cost);
    }

    sort(ans.begin(), ans.end());
    return ans[0];
}


int main() {

    vector<vector<int>> s = {{4,8,2}, {4,5,7}, {6,1,6}};

    cout<<formingMagicSquare(s)<<endl;

    return 0;
}


