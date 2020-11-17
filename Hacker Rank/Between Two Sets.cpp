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


int getTotalX(vector<int> a, vector<int> b) {

    int l=a[0], g=b[0];
    for (int i=1 ; i<a.size() ; i++) {
        l=lcm(l,a[i]);
    }
    cout<<l<<endl;

    for (int i=1 ; i<b.size() ; i++) {
        g=gcd(g,b[i]);
    }
    cout<<g<<endl;

    int ans=0;
    for (int i=l ; i<=b[0] ;) {
        if (g%i==0) ans++;
        i+=l;
    }


    return ans;
}

int main() {

    vector<int> a = {2, 6};
    vector<int> b = {24, 36};

    cout<<getTotalX(a, b)<<endl;

    return 0;
}


