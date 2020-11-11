#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    long r=2;
    vector<long> arr = {1,2,1,2,4};

    long ans=0;
    
    map<int, int>dict, back;
    for (int i=0 ; i<arr.size() ; i++) dict[arr[i]]++;

    if (r==1) {
        map<int, int>::iterator iter;
        for (iter=dict.begin() ; iter!=dict.end() ; iter++) {
            long t = iter->second;
            ans += ( t*(t-1)*(t-2) )/6;
        }
        cout<<ans<<endl;
        return ans;
    }

    for (int i=0 ; i<arr.size() ; i++) {
        dict[arr[i]]--;
        if (arr[i]%r==0) {
            ans += back[arr[i]/r]*1*dict[arr[i]*r];
        }
        back[arr[i]]++;
    }
    
    cout<<ans<<endl;
    return ans;
}
