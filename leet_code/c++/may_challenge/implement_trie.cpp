#include <map>
#include <string>

using namespace std;

class Trie {
 public:
  /** Initialize your data structure here. */
  map<char, Trie*> children;
  bool isWord;

  Trie() { isWord = false; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* current = this;
    for (char ch : word) {
      if (!current->children[ch]) {
        current->children[ch] = new Trie();
      }
      current = current->children[ch];
    }
    current->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* current = this;
    for (char ch : word) {
      if (!current->children[ch]) {
        return false;
      }
      current = current->children[ch];
    }
    return !!current && current->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trie* current = this;
    for (char ch : prefix) {
      if (!current->children[ch]) {
        return false;
      }
      current = current->children[ch];
    }
    return !!current;
  }
};