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

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    
    vector<int> q;
    k%=a.size();
    if (k!=0) {
        for (int i=0 ; i<k ; i++) q.push_back(a[a.size()-k+i]);
        for (int i=0 ; i<a.size()-k ; i++) q.push_back(a[i]);
    }
    else q=a;

    vector<int>ans;
    for (int i=0 ; i<queries.size() ; i++) {
        ans.push_back(q[queries[i]]);
        cout<<q[queries[i]]<<endl;
    }
    return ans;
}




int main() {

    int k=2;
    vector<int> a={1,2,3};
    vector<int> queries={0,1,2};

    circularArrayRotation(a,k,queries);
    return 0;
}

