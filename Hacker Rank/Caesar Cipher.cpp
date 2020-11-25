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

string caesarCipher(string s, int k) {

    k%=26;

    for (int i=0 ; i<s.size() ; i++) {
        if (s[i]>='a' && s[i]<='z') {
            if (s[i]+k>'z') {
                s[i] = 'a'+(((s[i]-'a')+k)%26);
            }
            else s[i] = s[i]+k;
        }
        else if (s[i]>='A' && s[i]<='Z') {
            if (s[i]+k>'Z') {
                s[i] = 'A'+(((s[i]-'A')+k)%26);
            }
            else s[i] = s[i]+k;
        }
    }
    return s;
}

int main() {

    string s = "middle-Outz";
    int k=5;
    cout<<caesarCipher(s,k);
    
    return 0;
}

