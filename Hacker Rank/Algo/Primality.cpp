#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

string primality(int n) {
    
    if (n<2) return "Not prime";
    else if (n==2) return "Prime";
    else if (n==3) return "Prime";
    else {
        if (n%2==0) return "Not prime";
        for (int i=3 ; i<int(sqrt(n)+1) ; i+=2) {
            if (n%i==0) return "Not prime";
        }
        return "Prime";
    }
}

int main() {

    int n=20;

    cout<<primality(n)<<endl;

    return 0;
}
