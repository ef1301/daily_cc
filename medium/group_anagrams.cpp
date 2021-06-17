#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
      for(string s: strs) {
        sort(s.begin(), s.end());
        mp[s].push_back(s);
      }
      vector<vector<string>> ans;
      for(auto p: mp) {
        ans.push_back(p.second);
      }
      return ans;
    }
};
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string,vector<string>> mp;
  for(string s: strs) {
    string temp = s;
    sort(temp.begin(), temp.end());
    mp[s].push_back(s);
  }
  vector<vector<string>> ans;
  for(auto p: mp) {
    ans.push_back(p.second);
  }
  return ans;
}

int main() {
  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> v =groupAnagrams(strs);
  for(auto i: v) {
    for(auto j: i) {
      cout << j << " ";
    }
  }

  return 0;
}
