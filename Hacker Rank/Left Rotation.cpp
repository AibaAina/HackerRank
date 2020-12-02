#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {

    vector<int> ans;

    int r=d%arr.size();
    if (r==0) return arr;
    else {
        for (int i=r ; i<arr.size() ; i++) {
            ans.push_back(arr[i]);
        }
        for (int i=0 ; i<r ; i++) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}


int main() {

    int d=2;
    vector<int> arr ={1,2,3,4,5};

    vector<int> z = rotateLeft(d, arr);
    for (int i : z) cout<<i;
    cout<<endl;

    return 0;
}

