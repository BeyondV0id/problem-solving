// @leet imports start
#include <bits/stdc++.h>
using namespace std;
// @leet imports end

// @leet start

struct TrieNode{
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
      isEnd = false;
      for(int i = 0; i < 26; i++){
        children[i] = NULL;
      }
    }
};

class Trie {
private:
  TrieNode* root;
public:
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode* curr = root;
      for(char c: word){
        int indx = c - 'a';
        if(curr->children[indx] == NULL){
          curr->children[indx] = new TrieNode();
        }
        curr = curr->children[indx];
      }
      curr->isEnd = true;
    }
    
    bool search(string word) {
      TrieNode*curr = root;
      for(char c: word){
        int indx = c-'a';
        if(curr->children[indx] == NULL){
          return false;
        }
        curr = curr->children[indx];
      }
      return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
      TrieNode* curr = root;
      for(char c : prefix){
        int indx = c - 'a';
        if(curr->children[indx] == NULL){
          return false;
        }
        curr = curr->children[indx];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
