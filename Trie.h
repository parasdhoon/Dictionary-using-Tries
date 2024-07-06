#ifndef TRIES
#define TRIES

//Including all the required Header Files
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Defining node structure for Trie Node
class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool isEnd;

        TrieNode() : isEnd(false){}
};

// Defininf the interface
class Trie {
    private:
        TrieNode* root;

        void autoCompleteHelper(TrieNode* node, string prefix, vector<string>& results);
        
    public:
        Trie() : root(new TrieNode()) {}

        void insert(const string& word);

        bool search(const string& word);

        vector<string> autoComplete(const string& prefix);
};

#endif