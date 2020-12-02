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

int saveThePrisoner(int n, int m, int s) {
    return ((m-1)+(s-1))%n+1;
}



int main() {

    vector<int> arr={-1,-1,0,1,1};
    int n=7, m=19, s=2;

    saveThePrisoner(n,m,s);
    return 0;
}

