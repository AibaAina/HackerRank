#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int d=4;
    vector<int> expenditure = {1,2,3,4,4};

    int ans=0;

    map<int, int> m;
    queue<int> q;

    for (int i=0 ; i<expenditure.size() ; i++) {
        if (i<d) {
            m[expenditure[i]]++;
            q.push(expenditure[i]);
        }
        else {
            if (d%2==1) {
                int target = d/2+1;
                map<int, int>::iterator iter;
                for (iter=m.begin() ; iter!=m.end();) {
                    target -= iter->second;
                    if (target>0) iter++;
                    else { 
                        ans += (expenditure[i]>=iter->first*2) ? 1:0;
                        break;
                    }
                }
            }
            else if (d%2==0) {
                int count[2] = {d/2, d/2+1};
                int target[2] = {0,0};
                map<int, int>::iterator iter;
                for (iter=m.begin() ; iter!=m.end();) {
                    count[0]-= iter->second;
                    count[1]-= iter->second;
                    if (count[1]==1) {
                        target[0]=iter->first;
                        iter++;
                    }
                    else if (count[0]>0) iter++;
                    else if (count[0]<=0 && count[1]<=0) {
                        if (target[0]==0) target[0]=iter->first;
                        ans += (expenditure[i]>=(target[0]+iter->first)) ? 1:0;
                        break;
                    }
                }
            }
            m[expenditure[i]]++;
            q.push(expenditure[i]);
            
            m[q.front()]--;
            q.pop();
        }
    }

    cout<<ans<<endl;
    return ans;
}
