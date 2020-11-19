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

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    int top = r_q-1;
    int bottom = n-r_q;
    int right = n-c_q;
    int left = c_q-1;

    int tr = min(top, right);
    int br = min(bottom, right);
    int bl = min(bottom, left);
    int tl = min(top, left);

    for (vector<int> v : obstacles) {

        if (v[0]==r_q) {
            if (v[1]<c_q)  left = min(left, c_q-v[1]-1);
            else right = min(right, v[1]-c_q-1);
        }
        else if (v[1]==c_q) {
            if (v[0]<r_q) top = min(top, r_q-v[0]-1);
            else bottom = min(bottom, v[0]-r_q-1);
        }

        else if (abs(v[0]-r_q) == abs(v[1]-c_q)) {
            // top left
            if (v[0]<r_q && v[1]<c_q)
                tl = min(tl, r_q-v[0]-1);

            // top right
            else if (v[0]<r_q && v[1]>c_q) 
                tr = min(tr, r_q-v[0]-1);

            // bottom left
            else if (v[0]>r_q && v[1]<c_q)
                bl = min(bl, v[0]-r_q-1);

            // bottom right
            else if (v[0]>r_q && v[1]>c_q)
                br = min(br, v[0]-r_q-1);
        }
    }
    return top+bottom+right+left+tl+tr+bl+br;
}

int main() {

    int n=5;
    int k=3;
    int r_q=4, c_q=3;
    vector<vector<int>> obstacles = {{5,5},{4,2},{2,3},{2,5},{2,1},{5,2},{5,4}};

    cout<<queensAttack(n,k,r_q,c_q,obstacles);

    return 0;
}


