#include "Trie.h"

int main() {
    Trie dictionary;

    // Inserting words into dictionary
    dictionary.insert("apple");
    dictionary.insert("app");
    dictionary.insert("appricot");
    dictionary.insert("banana");
    dictionary.insert("bat");
    dictionary.insert("batch");
    dictionary.insert("batman");

    // Search Words
    cout << (dictionary.search("apple") ? "Found apple" : "apple not found") << endl;
    cout << (dictionary.search("app") ? "Found app" : "app not found") << endl;
    cout << (dictionary.search("appricott") ? "Found appricott" : "appricott not found") << endl;
    cout << (dictionary.search("batman") ? "Found batman" : "batman not found") << endl;
    cout << (dictionary.search("batwoman") ? "Found batwoman" : "batwoman not found") << endl;


    // Auto - completion
    vector<string> complete = dictionary.autoComplete("ba");
    for(auto ele : complete) {
        cout << ele << ' ';
    }
    cout << endl;

    return 0;
}