
#include "../include/TrieTree.h"
#include <initializer_list>

namespace my {

    // Constructor
    Trie::Trie()
        : m_root(new TrieNode())
    {
    }

    // Destructor
    Trie::~Trie()
    {
        destroy_node(m_root);
    }

    Trie::Trie(std::initializer_list<std::string> init_list)
        : Trie()
    {
        for (const auto& word : init_list)
        {
            this->insert(word);
        }
    }

    // Insert a word into the Trie
    void Trie::insert(const std::string& word)
    {
        TrieNode* node = m_root;
        for (char ch : word)
        {
            if (!node->children.count(ch))
            {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }

    // Search for a word in the Trie
    bool Trie::search(const std::string& word) const
    {
        TrieNode* node = find_node(word);
        return node != nullptr && node->is_end_of_word;
    }

    // Check if any word starts with the given prefix
    bool Trie::starts_with(const std::string& prefix) const
    {
        return find_node(prefix) != nullptr;
    }

    // Remove a word from the Trie
    void Trie::remove(const std::string& word)
    {
        remove_helper(m_root, word, 0);
    }

    // Get all words stored in the Trie
    std::vector<std::string> Trie::get_all_words() const
    {
        std::vector<std::string> words;
        get_words_from_node(m_root, "", words);
        return words;
    }

    // Helper function to destroy a TrieNode recursively
    void Trie::destroy_node(TrieNode* node)
    {
        if (!node)
            return;

        for (auto& [ch, child] : node->children)
        {
            destroy_node(child);
        }
        delete node;
    }

    // Helper function to find the node corresponding to a given prefix
    Trie::TrieNode* Trie::find_node(const std::string& prefix) const
    {
        TrieNode* node = m_root;
        for (char ch : prefix)
        {
            if (!node->children.count(ch))
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

    // Helper function to collect words from a node
    void Trie::get_words_from_node(TrieNode* node, std::string current_prefix, std::vector<std::string>& words) const
    {
        if (node->is_end_of_word)
        {
            words.push_back(current_prefix);
        }
        for (const auto& [ch, child] : node->children)
        {
            get_words_from_node(child, current_prefix + ch, words);
        }
    }

    // Helper function to remove a word from the Trie
    bool Trie::remove_helper(TrieNode* node, const std::string& word, size_t depth)
    {
        if (!node)
            return false;

        if (depth == word.size())
        {
            if (!node->is_end_of_word)
                return false;
            node->is_end_of_word = false;
            return node->children.empty();
        }

        char ch = word[depth];
        if (!node->children.count(ch) || !remove_helper(node->children[ch], word, depth + 1))
        {
            return false;
        }

        delete node->children[ch];
        node->children.erase(ch);
        return !node->is_end_of_word && node->children.empty();
    }

} // namespace my