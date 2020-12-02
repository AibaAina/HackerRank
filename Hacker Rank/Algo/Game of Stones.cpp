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

string gameOfStones(int n) {
    n%=7;
    if (n==0 || n==1) return "Second";
    else return "First";
}

int main() {

    int n=7;
    gameOfStones(n);

    return 0;
}

