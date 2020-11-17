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

int gcd (int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

int lcm (int x, int y) {
    if (x==y) return x;
    int z = gcd(x,y);
    return (x*y)/z;
}

int main() {

    vector<int> a = {2, 6};
    vector<int> b = {24, 36};

    return 0;
}

