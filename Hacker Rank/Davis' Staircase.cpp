#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

int step(int n) {
    
    if (n<0) return 0;
    if (n==0) return 1;
    if (m.find(n)!=m.end()) return m[n];

    else return step(n-1)+step(n-2)+step(n-3);
}

int main() {

    int n = 7;
    
    int ans=0;

    // create dict 1-10
    for (int i=0 ; i<10 ; i++) {
        int temp = step(i-1)+step(i-2)+step(i-3);
        m[i]=temp;
    }

    ans = step(n-1)+step(n-2)+step(n-3);

    cout<<ans<<endl;
    return ans;
}

