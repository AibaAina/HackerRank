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

vector<string> split_string(string);

int dfs (vector<vector<int>> &v, int src, vector<bool> &visited ) {

    visited[src]=true;
    int ans=1;
    for (int i=0 ; i<v[src].size() ; i++) {
        if (!visited[v[src][i]]) {
            ans += dfs(v, v[src][i], visited);
        }
    }
    return ans;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    
    // if (c_road>c_lib) return c_lib*n;
    
    vector<vector<int>> v(n+1);
    for (int i=0 ; i<cities.size() ; i++) {
        v[cities[i][0]].push_back(cities[i][1]);
        v[cities[i][1]].push_back(cities[i][0]);
    }

    // size of each component
    vector<int> comps;
    vector<bool> visited(n+1, false);

    for (int i=1 ; i<=n ; i++) {
        if (v[i].size()>0 && !visited[i])
            comps.push_back(dfs(v, i, visited));
        else if (v[i].size()==0) 
            comps.push_back(1);
    }

    long long ans=0;
    for(int i=0 ; i<comps.size() ; i++) {
        ans += min((comps[i]-1)*c_road+c_lib, comps[i]*c_lib);
    }
    return ans;
}
