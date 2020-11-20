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

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {

    vector<int> sum(container.size(), 0);
    vector<int> row(container.size(), 0);
    
    for (int i=0 ; i<container.size() ; i++) {
        for(int j=0 ; j<container.size() ; j++) {
            sum[j]+=container[i][j];
            row[i]+=container[i][j];
        }
    }
    sort(row.begin(), row.end());
    sort(sum.begin(), sum.end());

    bool check =true;

    for (int i=0 ; i<container.size() ; i++) {
        if (row[i]!=sum[i]) {
            check=false;
            break;
        }
    }
    if (check)
            return "Possible";
    else
        return "Impossible";
}
int main() {
    
    return 0;
}
