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

string biggerIsGreater(string w) {

    string ans="";

    string s=w;
    sort(w.rbegin(), w.rend());
    if (s==w) return "no answer";
    else {
        string temp;
        int i;
        for (i=s.size()-2 ; i>=0 ; i--) {
            if (s[i]<s[i+1]) {
                temp = s.substr(i+1, s.size()-i);
                break;
            }
        }
        string tt=temp;
        sort(temp.rbegin(), temp.rend());


        string news = s[i]+tt;
        sort(news.begin(), news.end());
        ans+=s.substr(0,i);
        for (int c=0 ; c<news.size() ; c++) {
            if (news[c]==s[i]) {
                for (int cc=c+1 ; cc<news.size() ; cc++) {
                    if (news[cc]!=s[i]) {
                        c=cc;
                        break;
                    }
                }
                ans+=news[c];
                news.erase(news.begin()+c);
                ans+=news;
                break;
            }
        }

    }
    return ans;
}


int main() {

    string s1="fedcbabcd";
    string s2="dcba";
    string s3="abdc";
    string s4="zalqxykemvzzgkaa";
    string s5="zzzayybbaa";

    cout<<biggerIsGreater(s1)<<endl;

    return 0;
}


