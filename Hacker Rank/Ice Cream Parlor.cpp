#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    vector<int> cost={4,3,2,5,7};
    int money = 8;

    unordered_map<int, int> map;
    vector<int> ans;
    
    for (int i=0 ; i<cost.size() ; i++) {
        map[cost[i]]=i;
    }
    
    for (int i=0 ; i<cost.size() ; i++) {
        int t=money-cost[i];
        if (map.count(t) && map[t]!=i) {
            ans.push_back(i);
            ans.push_back(map[t]);
            break;
        }
    }

    cout<<ans[0]+1<<" "<<ans[1]+1<<endl;
    return 0;
}
