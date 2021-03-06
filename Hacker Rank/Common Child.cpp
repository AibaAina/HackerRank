#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

   string s1 = "ABC";
   string s2 = "AAAA";

   vector<vector<int>> ans (s1.size()+1, vector<int>(s2.size()+1));

   for (int i=0 ; i<s1.size()+1 ; i++) {
      for (int j=0 ; j<s2.size()+1 ; j++) 
         ans[i][j]=0;
   }

   for (int i=0 ; i<s1.size() ; i++) {
      for (int j=0 ; j<s2.size() ; j++) {
         if (s1[i]==s2[j]) {
            ans[i+1][j+1] = ans[i][j]+1;
         }
         else {
            ans[i+1][j+1] = max(ans[i][j+1], ans[i+1][j]);
         }
      }
   }

   cout<<ans[s1.size()][s2.size()]<<endl;
   return ans[s1.size()][s2.size()];
}

