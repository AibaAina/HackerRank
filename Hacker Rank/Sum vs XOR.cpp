
// example : 10
// match_pair  1010   SUM   XOR
//           0 0000  1010  1010
//           1 0001  1011  1011
//           4 0100  1110  1110
//           5 0101  1111  1111

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

long sumXor(long n) {
    
    int power=0;
    while (n>0) {
        if (n%2==0) power++;
        n/=2;
    }
    
    return pow(2, power);
}

int main() {

    long n=10;
    sumXor(n);

    return 0;
}

