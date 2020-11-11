#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    string s;
    cin>>s;

    int ans=0;
    unordered_map<string, int> map;

    for (int window=1 ; window<=s.size() ; window++) {
        string temp="";
        for (int i=0 ; i<s.size()-window+1 ; i++) {
            temp = s.substr(i,window);
            sort(temp.begin(), temp.end());
            map[temp]++;
        }
    }

    unordered_map<string, int>::iterator iter;
    for (iter=map.begin() ; iter!=map.end() ; iter++) {
        // cout<<iter->first<<" "<<iter->second<<endl;
        if (iter->second>1) 
            ans += iter->second*(iter->second-1)/2;
    }

    cout<<ans<<endl;
    return ans;
}