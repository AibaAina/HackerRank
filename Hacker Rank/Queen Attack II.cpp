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
    
    int ans=0;

    vector<vector<int>>board(n+1, vector<int>(n+1, 0));
    for (vector<int> v:obstacles) board[v[0]][v[1]]=1;
    board[r_q][c_q]=1;

    int i,j;
    
    // vertical
    for (i=1, j=c_q ; i<=n ; i++) 
        if (board[i][j]==0) ans++;
    // horizon
    for (i=r_q, j=1 ; j<=n ; j++) 
        if (board[i][j]==0) ans++;
    // left top
    for (i=r_q, j=c_q ; i>0 && j>0 ; i--, j--) 
        if (board[i][j]==0) ans++;
    // right top
    for (i=r_q, j=c_q ; i>0 && j<=n ; i--, j++) 
        if (board[i][j]==0) ans++;
    // left down
    for (i=r_q, j=c_q ; i<=n && j>0 ; i++, j--) 
        if (board[i][j]==0) ans++;
    // right down
    for (i=r_q, j=c_q ; i<=n && j<=n ; i++, j++) 
        if (board[i][j]==0) ans++;
    
    return ans;
}

int main() {

    int n=5;
    int k=3;
    int r_q=4, c_q=3;
    vector<vector<int>> obstacles = {{5,5},{4,2},{2,3}};

    cout<<queensAttack(n,k,r_q,c_q,obstacles);

    return 0;
}


