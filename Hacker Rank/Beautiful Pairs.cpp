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

int beautifulPairs(vector<int> A, vector<int> B) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans=0;
    int i=0, j=0;
    while (i<A.size() && j<B.size()) {
        if (A[i]<B[j]) i++;
        else if (A[i]>B[j]) j++;
        else {
            ans++;
            A.erase(A.begin()+i);
            B.erase(B.begin()+j);
        }
    }
    if (A.size()==0 && B.size()==0) ans--;
    else if (A.size()>0 && B.size()>0) ans++;
    return ans;
}

int main() {
    
    // string s = "face";
    // sort(s.begin(), s.end());
    // cout<<s;
    vector<int> A = {3, 5, 7, 11, 5, 8};
    vector<int> B = {5, 7, 11, 10, 5, 8};

    cout<<beautifulPairs(A,B);

    return 0;
}

