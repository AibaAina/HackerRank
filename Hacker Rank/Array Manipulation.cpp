#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int n=10;
    vector<vector<int>> queries = {{1,5,3},{4,8,7},{6,9,1}};

    long ans=0;

    vector<long> v(n+1,0);

    for (int i=0 ; i<queries.size() ; i++) {
        v[queries[i][0]-1] += queries[i][2];
        v[queries[i][1]] -= queries[i][2];
    }

    long sum=0;
    for (int i=0 ; i<n ; i++) {
        sum += v[i];
        ans = ans>sum? ans:sum;
    }

    cout<<ans<<endl;
    return ans;
}
