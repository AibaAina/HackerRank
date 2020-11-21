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

int beautifulTriplets(int d, vector<int> arr) {
    
    int ans=0;

    map<int, int>dict;
    for (int i:arr) dict[i]++;

    map<int, int>::iterator iter;
    for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
        if (iter->first==arr[arr.size()-1]) break;
        vector<int> q;
        q.push_back(iter->second);
        int pos=iter->first;
        while (1) {
            pos+=d;
            if (dict[pos]>0) {
                q.push_back(dict[pos]);
                if (q.size()==3) {
                    ans += q[0]*q[1]*q[2];
                    break;
                }
            }
            else break;
        }
    }

    return ans;
}

int main() {

    int d=3;
    vector<int> arr = {1, 2, 4, 5, 7, 8, 10};

    cout<<beautifulTriplets(d,arr);

    return 0;
}


