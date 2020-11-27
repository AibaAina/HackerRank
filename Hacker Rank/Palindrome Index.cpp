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



int palindromeIndex(string s) {

    int ans=-1;
    int i=0, j=s.size()-1;
    
    while (i<j) {
        if (s[i]!=s[j]) {
            if (i+1==j) return i;
            //skip left
            int left=i+1;
            if ((left+j)%2==0) {
                int mid=(left+j)/2;
                if (s[mid+1]==s[mid-1]) {
                    return i;
                }
            }
            else {
                int mid=(left+j)/2;
                if (s[mid]==s[mid+1]) {
                    return i;
                }
            }

            // skip right
            int right=j-1;
            if ((i+right)%2==0) {
                int mid=(i+right)/2;
                if (s[mid+1]==s[mid-1]) {
                    return j;
                }
            }
            else {
                int mid=(i+right)/2;
                if (s[mid]==s[mid+1]) {
                    return j;
                }
            }
        }
        i++;
        j--;
    }
    return ans;
}

int main() {

    vector<string> arr = {"abcdde", "baccd", "eeabg"};
    string b = "hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh";
    cout<<palindromeIndex(b);
    
    return 0;
}

