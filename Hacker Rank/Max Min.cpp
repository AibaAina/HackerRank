#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int k=3;
    vector<int> arr = {10, 100, 300, 200, 1000, 20, 30, 40};

    int ans=INT_MAX;
    
    sort(arr.begin(), arr.end());
    for (int i=k-1 ; i<arr.size() ; i++) {
        ans = ans<(arr[i]-arr[i-k+1]) ? ans:(arr[i]-arr[i-k+1]);
    }
    

    cout<<ans<<endl;
    return ans;
}