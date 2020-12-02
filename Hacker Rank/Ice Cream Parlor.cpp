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

void whatFlavors(vector<int> cost, int money) {

    unordered_map<int, int>dict;

    for (int i=0 ; i<cost.size() ; i++) dict[cost[i]]=i;
    for (int i=0 ; i<cost.size() ; i++) {
        int tar = money-cost[i];
        if (dict[tar]>0 && dict[tar]!=i) {
            cout<<i+1<<" "<<dict[tar]+1<<endl;
        }
    }
}

int main() {

    vector<int> cost = {1, 4, 5, 3, 2};
    int money=4;
    string s = "hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh";
    whatFlavors(cost, money);

    return 0;
}

