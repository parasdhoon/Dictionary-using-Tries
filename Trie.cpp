#include "Trie.h"

void Trie :: insert(const string& word) {
    TrieNode* current = root;
    for(auto c : word) {
        if(current -> children.find(c) == current -> children.end()) {
            current -> children[c] = new TrieNode();
        }
        current = current -> children[c];
    }
    current -> isEnd = true;
}

bool Trie :: search(const string& word) {
    TrieNode* current = root;
    for(auto c : word) {
        if(current -> children.find(c) == current -> children.end()) {
            return false;
        }
        current = current -> children[c];
    }
    return current -> isEnd;
}

vector<string> Trie :: autoComplete(const string& prefix) {
    TrieNode* current = root;
    for(auto c : prefix) {
        if(current -> children.find(c) == current -> children.end()) {
            return {};
        }
        current = current -> children[c];
    }
    vector<string> results;
    autoCompleteHelper(current, prefix, results);
    return results;
}

void Trie :: autoCompleteHelper(TrieNode* node, string prefix, vector<string>& results) {
    if(node -> isEnd) {
        results.push_back(prefix);
    }

    for(auto it : node -> children) {
        autoCompleteHelper(it.second, prefix + it.first, results);
    }
}