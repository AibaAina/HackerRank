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

void printarr (vector<int> arr) {
    for (int a:arr)
        cout<<a<<" ";
    cout<<endl;
}

void insertionSort1(vector<int> arr) {
    int take;
    for (int i=1 ; i<arr.size() ; i++) {
        if (arr[i]<arr[i-1]) {
            take=arr[i];
            bool end=true;
            int j;
            for (j=i ; j>0 ; j--) {
                if (arr[j-1]<take) {
                    arr[j]=take;
                    end=false;
                    break;
                }
                arr[j]=arr[j-1];
                // printarr(arr);
            }
            if (end) arr[j]=take;
            // printarr(arr);
        }
    }
    printarr(arr);
}

int main() {

    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    insertionSort1(arr);
    return 0;
}


