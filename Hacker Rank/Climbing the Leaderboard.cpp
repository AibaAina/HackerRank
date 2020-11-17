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

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    
    vector<int> ans;
    stack<int> scores;

    for (int r : ranked) {
        if (scores.empty() || scores.top()!=r) {
            scores.push(r);
        }
    }

    for (int p : player) {
        while (!scores.empty() && p>=scores.top()) scores.pop();
        // cout<<scores.size()+1<<endl;
        ans.push_back(scores.size()+1);
    }

    return ans;
}

int main() {

    vector<int> ranked = {100,100,50,40,40,20,10};
    vector<int> player = {5,25,50,120};

    vector<int> z = climbingLeaderboard(ranked, player);
    for (int i:z) cout<<i<<endl;

    return 0;
}


