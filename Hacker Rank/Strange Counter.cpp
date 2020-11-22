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

vector<long long> dict;

void calculate() {
    long long base=1;
    while (1) {
        base*=2;
        long long temp = base-1;
        dict.push_back(temp*3);
        if (dict[dict.size()-1]>1000000000000) break;
    }
}

long strangeCounter(long t) {
    long long ans=0;
    calculate();
    for (long long i: dict) {
        if (t==i) return 1;
        else if (t<i) {
            ans = 1+(i-t);
            break;
        }
    }
    return ans;
}

int main() {

    int t=9;
    cout<<strangeCounter(t);

    return 0;
}


