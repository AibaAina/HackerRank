#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    int k=2;
    string charValue="01111001111111111011111111";
    string s="giraffe";

    int ans=0;
    queue<char> q;
    int count=0;

    for (int i=0; i<s.size(); ) {
        if (q.empty() || charValue[s[i]-'a']=='1') {
            q.push(s[i++]);
            if (charValue[s[i]-'a']=='0') count++;
        }
        else {
            if (count<k) {
                count++;
                q.push(s[i++]);
            }
            else {
                ans = ans>q.size()? ans:q.size();
                // if q front is normal, pop out & count-1
                if (charValue[q.front()-'a']=='0') {
                    q.pop();
                    count--;
                }
                // if q front is special, pop out
                else {
                    q.pop();
                }
            }
        }
    }
    ans = ans>q.size()? ans:q.size();
    // cout<<ans<<endl;

    return 0;
}
