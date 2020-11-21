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

string timeInWords(int h, int m) {
    
    string ans="";

    vector<string> hours = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "one"};
    vector<string> mins = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                        "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five",
                        "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty", "thirty one", "thirty two", "thirty three", "thirty four", "thirty five",
                        "thirty six", "thirty seven", "thirty eight", "thirty nine", "forty", "forty one", "forty two", "forty three", "forty four", "forty five",
                        "forty six", "forty seven", "forty eight", "forty nine", "fifty", "fifty one", "fifty two", "fifty three", "fifty four", "fifty five",
                        "fifty six", "fifty seven", "fifty eight", "fifty nine", "sixty"};

    // cout<<mins[60]<<endl;
    if (m==0) ans += hours[h] + " o'clock";
    if (m==1) ans += "one minute past " + hours[h];
    else if (m==15) ans += "quarter past " + hours[h];
    else if (m==30) ans += "half past " + hours[h];
    else if (m==45) ans += "quarter to " + hours[h+1];
    else if (m<30) ans += mins[m] + " minutes past " + hours[h];
    else if (m<60) ans += mins[60-m] + " minutes to " + hours[h+1];


    return ans;
}

int main() {

    int h=5;
    int m=30;
    cout<<timeInWords(h,m);

    return 0;
}


