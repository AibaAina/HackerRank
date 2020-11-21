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

bool check(int x) {

    long long m = x;

    int d = to_string(x).size();
    long long square = m*m;

    string s = to_string(square);
    string s1 = s.substr(0, s.size()-d);

    string s2 = s.substr(s.size()-d ,d);

    int ans=0;
    if (s1.size()!=0) ans = stoi(s1)+stoi(s2);
    else ans = stoi(s2);

    return ans==x?true:false;
}

void kaprekarNumbers(int p, int q) {
    
    vector<int> ans;

    for (int i=p ; i<=q ; i++) 
        if (check(i)) ans.push_back(i);

    if (ans.size()==0) cout<<"INVALID RANGE"<<endl;
    else {
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
    }
}

int main() {

    int p=1, q=99999;

    kaprekarNumbers(p,q);

    return 0;
}


