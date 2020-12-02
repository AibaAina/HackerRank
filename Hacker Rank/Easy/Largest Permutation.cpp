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

vector<int> largestPermutation(int k, vector<int> arr) {
    int n=arr.size();
    vector<int> index(n+1,0);
    for (int i=0 ; i<n ; i++) index[arr[i]]=i;

    int i=0;
    while(k>0 && i<n) {
        if (arr[i]!=n-i) {
            arr[index[n-i]] = arr[i];
            index[arr[i]] = index[n-i];
            arr[i] = n-i;
            index[n-i] = i;
            k--;
        }
        i++;
    }

    return arr;
}

int main() {

    vector<int> order = {4, 2, 3, 5, 1};
    int k=1;
    largestPermutation(k, order);

    return 0;
}

