/*
Invertion = numbers of element's value which is less than current element's value.
each rotation need (window_size-1) times swap
Invertion % (window_size-1) == 0? YES:NO

15 Tiles Game
https://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html
*/

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

string larrysArray(vector<int> A) {

    int invertion=0;
    for (int i=0 ; i<A.size() ; i++) {
        for (int j=i+1 ; j<A.size() ; j++) {
            if (A[i]>A[j]) invertion++;
        }
    }
    
    return invertion%2==0?"YES":"NO";
}

int main() {

    vector<int> A = {1, 2, 3, 5, 4};

    cout<<larrysArray(A)<<endl;
    return 0;
}


