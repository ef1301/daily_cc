#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> permutation(vector<string> strs, vector<int> pn) {
  for(vector<string>::iterator it =strs.begin(); it != strs.end(); it++) {
    vector<string>::iterator next = it;
    while(pn[next] >= 0) {
      swap(strs[i],strs[pn[next]]);
      int temp = pn[next];
      pn[next] -= n;
      next = temp;
    }
  }
  return strs;
}

int main() {
  return 0;
}
