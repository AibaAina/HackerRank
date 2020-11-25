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
    string code = "abcdefghijklmnopqrstuvwxyz";
    string Big = "ABCDEFG";

    for (int i=0 ; i<26 ; i++) {
        if (code[i]+k>'z') {
            code[i] = 'a'+((code[i]+k)%26);
        }
        else code[i] = code[i]+k;

        cout<<code[i]<<" ";
    }
    return "";

    // for (int i=0 ; i<s.size() ; i++) {
    //     if (s[i]>='a' && s[i]<='z') {
    //         if (s[i]+k>'z') {
    //             s[i] = 'a'+((s[i]+k)%26);
    //         }
    //         else s[i] = s[i]+k;
    //     }
    //     else if (s[i]>='A' && s[i]<='Z') {
    //         if (s[i]+k>'Z') {
    //             s[i] = 'A'+((s[i]+k)%26);
    //         }
    //         else s[i] = s[i]+k;
    //     }
    // }
    return s;
}

int main() {

    string s = "middle-Outz";
    int k=5;
    cout<<caesarCipher(s,k);
    
    return 0;
}

