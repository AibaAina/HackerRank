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

string isValid(string s) {
    
    unordered_map<char, int>map, map2;
    
    for (int i=0 ; i<s.size() ; i++)
        map[s[i]]++;
    
    unordered_map<char, int>::iterator iter;
    for (iter=map.begin() ; iter!=map.end() ; iter++) {
        map2[iter->second]++;
    }
    
    // cout<<"size= "<<map2.size()<<endl;
    if (map2.size()>2) return "NO";
    else if (map2.size()==2) {
        
        vector<int>z;
        for (iter=map2.begin();iter!=map2.end();iter++) {
            z.push_back(iter->first);
            z.push_back(iter->second);
        }
        
        if (z[1]>z[3]) {
            swap(z[1], z[3]);
            swap(z[0], z[2]);
        }
        
        if (z[1]==1) {
            if (z[0]-1==z[2])
                return "YES";
            if (z[0]-1==0)
                return "YES";
        }
        
        return "NO";
    }
    return "YES";
}

int main() {

    int n=5, k=3, r_q=4, c_q=3;
    vector<vector<int>> obstacles = {{5,5},{4,2},{2,3}};
    vector<long> arr = {1, 3, 9, 9, 27, 81};
    int ratio = 3;
    string s="aabbcd";
    cout<<isValid(s);

    return 0;
}

