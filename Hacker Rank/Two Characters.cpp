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

int alternate(string s) {

    if (s.size()==1) return 0;

    int ans=0;

    vector<vector<char>> board1(26, vector<char>(26,'*'));
    vector<vector<int>> board2(26, vector<int>(26,0));

    for (char c : s) {
        for (int i=0 ; i<26 ; i++) {
            if (board2[c-'a'][i]==-1) continue;

            if (c!=board1[c-'a'][i]) {
                board2[c-'a'][i]++;
                board1[c-'a'][i]=c;
            }
            else board2[c-'a'][i]=-1;
        }
        for (int i=0 ; i<26 ; i++) {
            if (board2[i][c-'a']==-1) continue;

            if (c!=board1[i][c-'a']) {
                board2[i][c-'a']++;
                board1[i][c-'a']=c;
            }
            else board2[i][c-'a']=-1;
        }
    }

    for (int i=0 ; i<26 ; i++) {
        for (int j=0 ; j<26 ; j++) {
            // cout<<board2[i][j]<<" ";
            ans = max(ans, board2[i][j]);
        }
        // cout<<endl;
    }

    return ans;
}

int main() {

    string s = "a";
    cout<<alternate(s)<<endl;
    
    return 0;
}

