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

vector<int> jimOrders(vector<vector<int>> orders) {
    
    vector<vector<int>> ans;
    for (int i=0 ; i<orders.size() ; i++) {
        int customer = i;
        int total = orders[i][0] + orders[i][1];
        if (ans.empty()) ans.push_back({customer,total});
        else {
            for (int a=ans.size()-1 ; a>=0 ; a--) {
                if (total>=ans[a][1]) {
                    ans.insert(ans.begin()+a+1, {customer,total});
                    break;
                }
                else if (a==0 && total<ans[a][1]) {
                    ans.insert(ans.begin(), {customer,total});
                    break;
                }
            }
        }
        // for (vector<int>v :ans) cout<<v[0]<<" "<<v[1]<<endl;
        // cout<<endl;
    }
    
    vector<int>z;
    for (vector<int>v :ans) {
        z.push_back(v[0]+1);
        cout<<v[0]+1<<endl;
    }
    return z;
}

int main() {

    string s = "aaaa";
    vector<vector<int>> order = {{1, 1}, {1, 1}};
    jimOrders(order);

    return 0;
}

