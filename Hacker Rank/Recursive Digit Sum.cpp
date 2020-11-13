#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

string deep(string bits, string ori, int c) {
    
    cout<<c<<endl;
    if (c==0) return bits;
    else {
        int temp=0;
        for (int i=0 ; i<bits.size() ; i++) temp += bits[i]-'0';
        string str=to_string(temp);

        return deep(str+ori, ori, c--);
    }
}

int main() {

    string n = "9875";
    int k = 4;

    int ans=0;

    string ori=n;
    int temp=0;
    for (int i=0 ; i<n.size() ; i++) 
        temp += n[i]-'0';
    ori=to_string(temp);

    string bits=ori;
    for (int i=1 ; i<k ; i++) {
        temp=0;
        for (int i=0 ; i<bits.size() ; i++) 
            temp += bits[i]-'0';
        bits=to_string(temp)+ori;
    }

    while (1) {
        int temp=0;
        for (int i=0 ; i<bits.size() ; i++) 
            temp += bits[i]-'0';
        if (temp<10) {
            ans=temp;
            break;
        }
        else bits=to_string(temp);
    }

    cout<<ans<<endl;
    return ans;
}

