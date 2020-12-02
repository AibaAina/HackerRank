#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int n=100;
    vector<vector<int>> queries={ {1,345255357,205970905}, {1,328743001 ,855677723}, {2,736380701 ,402184046} };

    vector<vector<int>> seq(n);
    int ans=0;
    vector<int>ret;

    for (vector<int> i : queries) {
        int temp;
        temp = (i[1]^ans)%n;
        cout<<"temp = "<<temp<<endl;

        if (i[0]==1) {
            seq[temp].push_back(i[2]);
        }
        else {
            ans = seq[temp][i[2]%seq[temp].size()];
            cout<<ans<<endl;
            ret.push_back(ans);
        }
    }
    
    return 0;
}

