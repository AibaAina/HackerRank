#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int ans=0;
    int row = A.size();
    int col = A[0].size();

    vector<vector<int>>board (row+2, vector<int>(col+2,0));

    for (int i=1 ; i<board.size()-1 ; i++) {
        for (int j=1 ; j<board[0].size()-1 ; j++) {
            board[i][j] = A[i-1][j-1];
        }
    }

    for (int i=1 ; i<board.size()-1 ; i++) {
        for (int j=1 ; j<board[0].size()-1 ; j++) {
            ans += max(0, board[i][j]-board[i-1][j]);
            ans += max(0, board[i][j]-board[i+1][j]);
            ans += max(0, board[i][j]-board[i][j-1]);
            ans += max(0, board[i][j]-board[i][j+1]);
        }
    }
    ans += A.size()*A[0].size()*2;
    return ans;
}

int main() {

    vector<vector<int>> A = {{1,3,4},{2,2,3},{1,2,4}};
    vector<vector<int>> B = {{51},{32},{28},{49},{28},{21},{98},{56},{99},{77}};
    cout<<surfaceArea(A);

    return 0;
}


