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

    vector<int> a={1,2,3,4};
    vector<int> ans;

    for (int i=a.size()-1 ; i>=0 ; i--) {
        ans.push_back(a[i]);
    }

    // cout<<ans<<endl;
    return 0;
}

