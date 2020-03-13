#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
  map<string, set<string>> table;
  vector<vector<string>> list;
  map<string, set<int>> eye;

  for (auto account : accounts) {
    set<string> emails;

    for (auto email = begin(account) + 1; email != end(account); ++email) {
      emails.insert(*email);
    }
  }

  for (auto account : accounts) {
    set<string> emails;

    for (auto email = begin(account) + 1; email != end(account); ++email) {
      emails.insert(*email);
    }

    if (eye.find(account[0]) != eye.end()) {
      for (auto i = eye[account[0]].begin(); i != eye[account[0]].end(); ++i) {
        list[*i];
      }
    }

    if (table.find(account[0]) == table.end()) {
      table[account[0]] = emails;
    } else {
      for (auto email = begin(emails); email != end(emails); ++email) {
        if (table[account[0]].find(*email) != table[account[0]].end()) {
          emails.insert(emails.begin(), emails.end());
          break;
        }
      }
    }
  }

  return list;
}