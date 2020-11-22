#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> ans;
    
    if (k==0) {
        for (int i=1 ; i<=n ; i++) 
            ans.push_back(i);
        return ans;
    }
    else if (n%(k*2)!=0) {
        ans.push_back(-1);
        return ans;
    }
    else {
        bool updown = true;
        for (int i=1 ; i<=n ; i++)  {
            if (updown) ans.push_back(i+k);
            else ans.push_back(i-k);

            if (i%k==0) updown = updown?false:true;
        }
    }
    return ans;
}

int main() {

    int n=10;
    int k=4;
    
    vector<int> z = absolutePermutation(n,k);
    if (z[0]==-1) cout<<"a";
    else for(int i:z) cout<<i<<" ";
    // cout<<endl<<"2 1 4 3 6 5 8 7 10 9"<<endl;

    return 0;
}


