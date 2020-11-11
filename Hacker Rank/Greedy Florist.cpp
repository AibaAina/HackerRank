#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int k=3;
    vector<int> c = {1, 3, 5, 7, 9};

    int ans=0;
    
    sort(c.rbegin(), c.rend());
    
    int count=k, ratio=1;
    for (int i=0 ; i<c.size() ; i++) {
        ans += c[i]*ratio;
        count--;
        if (count==0) {
            count=k;
            ratio++;
        }
    }

    cout<<ans<<endl;
    return ans;
}