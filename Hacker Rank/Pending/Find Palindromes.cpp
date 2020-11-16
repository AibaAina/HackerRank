#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

map<string, int> m;
vector<string> dict;

void find_palindromes_in_sub_string(const string& input, int j, int k) {

    for (;j>=0 && k<input.size() ; j--, k++) {
        if (input[j]!=input[k]) break;
        // m[input.substr(j, k-j+1)]++;
        dict.push_back(input.substr(j, k-j+1));
    }
}

void find_all_palindrome_substrings(const string& input) {
    for (int i=0 ; i<input.size() ; i++) {
        find_palindromes_in_sub_string(input, i-1, i+1);
        find_palindromes_in_sub_string(input, i, i+1);
    }
}

vector<int> solve(string s, vector<int> queries) {
    
    find_all_palindrome_substrings(s);

    for (int i=0 ; i<s.size() ; i++) {
        m[s.substr(i,1)]++;
        dict.push_back(s.substr(i,1));
    }
    sort(dict.begin(), dict.end());
    // for (string x : dict) cout<<x<<endl;

    vector<int> ans;
    for (int i:queries) {
        if (i>dict.size()) ans.push_back(-1);
        else {
            long long total=0;
            long long temp=1;
            for (int z=dict[i-1].size()-1 ; z>=0 ; z--) {
                total += (dict[i-1][z]*temp)%1000000007;
                total %= 1000000007;
                temp *= 100001;
            }
            ans.push_back(total);
        }
    }
    return ans;
}

int main() {

    string s = "abcba";
    vector<int> queries = {1,2,3,4,6,7,8};

    vector<int> sss = solve(s, queries);
    for (int i:sss) cout<<i<<endl;

    return 0;
}

