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

long substrCount(int n, string s) {
    
    int ans=n;

    for (int i=0 ; i<n ; i++) {
        char first = s[i];
        int change = -1;

        for (int j=i+1 ; j<n ; j++) {
            char cur = s[j];
            if (change==-1 && cur!=first) 
                change=j;
            else if (change==-1 && cur==first)
                ans++;
            else if (change!=-1 && cur!=first) 
                break;
            else if (change!=-1 && cur==first && change-i==j-change) {
                ans++;
                break;
            }
        }
    }
    
    return ans;
}

int main() {

    string s = "aaaa";
    int n =4;
    cout<<substrCount(n,s);

    return 0;
}

