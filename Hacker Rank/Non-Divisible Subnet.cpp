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

int nonDivisibleSubset(int k, vector<int> s) {
    
    int ans=0;

    map<int, int>dict;
    for (int i=0 ; i<k ; i++) dict[i]=0;
    for (int i : s) dict[i%k]++;

    // map<int, int>::iterator iter;
    // for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
    //     cout<<iter->first<<" "<<iter->second<<endl;
    // }

    if (k%2==0) {
        for (int i=1 ; i<k/2 ; i++) {
            ans += dict[i]>dict[k-i]?dict[i]:dict[k-i];
        }
        if (dict[k/2]>0) ans++;
    }
    else {
        for (int i=1 ; i<=k/2 ; i++) {
            ans += dict[i]>dict[k-i]?dict[i]:dict[k-i];
        }
    }
    
    if (dict[0]>0) ans++;
    return ans;
}

int main() {

    int k=4;
    vector<int>s = {19,10,12,10,24,25,22};

    cout<<nonDivisibleSubset(k,s);
    return 0;
}

