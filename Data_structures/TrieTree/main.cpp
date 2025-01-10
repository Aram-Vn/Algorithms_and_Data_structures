#include "include/TrieTree.h"
#include <cassert>
#include <iostream>

int main()
{
    my::Trie trie;

    // Insert words into the Trie
    trie.insert("hello");
    trie.insert("world");
    trie.insert("trie");
    trie.insert("tree");
    trie.insert("test");

    // Search for words
    assert(trie.search("hello") == true);
    assert(trie.search("world") == true);
    assert(trie.search("trie") == true);
    assert(trie.search("tree") == true);
    assert(trie.search("test") == true);
    assert(trie.search("nonexistent") == false);

    // Check if words start with a prefix
    assert(trie.starts_with("he") == true);
    assert(trie.starts_with("wo") == true);
    assert(trie.starts_with("tri") == true);
    assert(trie.starts_with("tre") == true);
    assert(trie.starts_with("te") == true);
    assert(trie.starts_with("non") == false);

    // Remove a word and check
    trie.remove("test");
    assert(trie.search("test") == false);

    // Print all words in the Trie
    std::vector<std::string> words = trie.get_all_words();
    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }

    std::cout << "All tests passed! default ctor" << std::endl;

    // Test for initializer list constructor
    my::Trie trie_init_list = { "hello", "world", "trie", "tree", "test" };

    // Search for words initialized through the initializer list
    assert(trie_init_list.search("hello") == true);
    assert(trie_init_list.search("world") == true);
    assert(trie_init_list.search("trie") == true);
    assert(trie_init_list.search("tree") == true);
    assert(trie_init_list.search("test") == true);
    assert(trie_init_list.search("nonexistent") == false);

    // Check if words start with a prefix
    assert(trie_init_list.starts_with("he") == true);
    assert(trie_init_list.starts_with("wo") == true);
    assert(trie_init_list.starts_with("tri") == true);
    assert(trie_init_list.starts_with("tre") == true);
    assert(trie_init_list.starts_with("te") == true);
    assert(trie_init_list.starts_with("non") == false);

    // Remove a word and check
    trie_init_list.remove("test");
    assert(trie_init_list.search("test") == false);

    // Print all words in the trie_init_list
    words = trie_init_list.get_all_words();
    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }

    std::cout << "All tests passed! init list" << std::endl;
    return 0;
}
