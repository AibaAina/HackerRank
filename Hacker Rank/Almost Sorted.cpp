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

void almostSorted(vector<int> arr) {

    if (is_sorted(arr.begin(), arr.end())) {
       cout<<"yes"<<endl;
       return;
    }
    else if (arr.size()==2) {
        cout<<"yes"<<endl;
        cout<<"swap 1 2"<<endl;
        return;
    }

    vector<int> peak, valley;
    
    for (int i=1 ; i<arr.size()-1 ; i++) {
        if (arr[i]>arr[i-1] && arr[i]>arr[i+1]) peak.push_back(i);
        else if (arr[i]<arr[i-1] && arr[i]<arr[i+1]) valley.push_back(i);
    }

    if (peak.size()==2 && valley.size()==2) {
        if ( arr[valley[1]]>arr[peak[0]-1] ) {
            if ( arr[valley[1]]<arr[peak[0]+1] ) {
                if ( arr[peak[0]]>arr[valley[1]-1]) {
                    if ( arr[peak[0]]<arr[valley[1]+1]) {
                        cout<<"yes"<<endl;
                        cout<<"swap "<<peak[0]+1<<" "<<valley[1]+1<<endl;
                        return;
                    }
                }
            }
        }
    }
    else if (peak.size()==1 && valley.size()==1) {
        if ( arr[peak[0]]<arr[valley[0]+1] ) {
            if ( arr[valley[0]]>arr[peak[0]-1] ) {
                if (valley[0]-peak[0]==1) {
                    cout<<"yes"<<endl;
                    cout<<"swap "<<peak[0]+1<<" "<<valley[0]+1<<endl;
                    return;
                }
                else {
                    cout<<"yes"<<endl;
                    cout<<"reverse "<<peak[0]+1<<" "<<valley[0]+1<<endl;
                    return;
                }
            }
        }
    }
    cout<<"no"<<endl;
    return;
}


int main() {

    vector<int> arr = {1, 5, 4, 3, 2, 6};
    vector<int> arr2 = {43, 65, 1, 98, 99, 101};
    almostSorted(arr2);
    
    return 0;
}

