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

bool compare(string i,string j) {

    int n=i.size();
    int m=j.size();

    if (n==m) return i<j;
    else return n<m;
}

vector<string> bigSorting(vector<string> unsorted) {
    
    sort(unsorted.begin(), unsorted.end(), compare);

    return unsorted;
}

int main() {

    vector<string> unsorted = {"1", "2", "100", "12303479849857341718340192371", "3084193741082937", "3084193741082938", "111", "200"};
    unsorted = bigSorting(unsorted);
    for (string s:unsorted) cout<<s<<endl;
    
    return 0;
}

