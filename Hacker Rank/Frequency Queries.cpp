#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    vector<vector<int>> queries = {{3, 4}, {2, 1003}, {1, 16}, {3, 1}};

    vector<int> ans;
    unordered_map<int, int> map, freq;

    for (int i=0 ; i<queries.size() ; i++) {
        if (queries[i][0]==1) {
            int temp=map[queries[i][1]];
            freq[temp] = freq[temp]>0 ? freq[temp]-1:0;

            map[queries[i][1]]++;
            freq[temp+1]++;
        }
        else if (queries[i][0]==2) {
            int temp=map[queries[i][1]];
            freq[temp] = freq[temp]>0 ? freq[temp]-1:0;

            map[queries[i][1]] = map[queries[i][1]]>0 ? map[queries[i][1]]-1:0;
            freq[temp-1]++;
        }
        else if (queries[i][0]==3) {
            if (freq[queries[i][1]]>0) ans.push_back(1);
            else ans.push_back(0);
        }
    }
    
    for (int i:ans)
        cout<<i<<endl;
    return 0;
}
