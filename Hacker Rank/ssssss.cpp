#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    
    vector<vector<char>>map(26, vector<char>(26, '*'));
    vector<vector<int>>ans(26, vector<int>(26, 0));
    
    for (char c:s) {
        for (int i=0 ; i<26 ; i++) {
            if (map[c-'a'][i]==c) {
                ans[c-'a'][i]=-1;
                break;
            }
            else {
                map[c-'a'][i]=c;
                ans[c-'a'][i]++;
            }
        }
        for (int i=0 ; i<26 ; i++) {
            if (map[i][c-'a']==c) {
                ans[i][c-'a']=-1;
                break;
            }
            else {
                map[i][c-'a']=c;
                ans[i][c-'a']++;
            }
        }
    }
    
    int z=0;
    for (vector<int>v:ans) {
        for (int i:v) {
            z=max(z,i);
        }
    }
    
    return z;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
