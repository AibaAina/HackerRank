#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int binarysearch (vector<int> list, int head, int tail, int target) {

    int mid;
    while (head<=tail) {
        mid=head+(tail-head)/2;

        if (target==list[mid]) return mid;
        else if (target>list[mid]) tail=mid-1;
        else head=mid+1;
    }

    return mid;
}


int main() {

    vector<int> z = {50,40,30,20,10};
    cout<<binarysearch(z,0,4,15)<<endl;

    return 0;
}


