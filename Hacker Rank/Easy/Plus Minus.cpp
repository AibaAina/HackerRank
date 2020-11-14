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

void plusMinus(vector<int> arr) {
    vector<double> count(3, 0);
    for (int i : arr) {
        if (i>0) count[0]++;
        if (i==0) count[2]++;
        if (i<0) count[1]++;
    }
    double ans;
    for (double i:count) {
        ans=i/arr.size();
        cout<<setprecision(6)<<ans<<endl;
    }
}


int main() {

    vector<int> arr={-1,-1,0,1,1};

    plusMinus(arr);
    return 0;
}

