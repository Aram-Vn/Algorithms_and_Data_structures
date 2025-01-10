
#ifndef __TRIE_TREE_INCLUDE_TRIE_TREE_H__
#define __TRIE_TREE_INCLUDE_TRIE_TREE_H__

#include <initializer_list>
#include <string>
#include <unordered_map>
#include <vector>

namespace my {

    class Trie
    {
    private:
        struct TrieNode
        {
            bool                                is_end_of_word;
            std::unordered_map<char, TrieNode*> children;

            TrieNode()
                : is_end_of_word(false)
            {
            }
        };

    public:
        Trie();
        ~Trie();
        Trie(std::initializer_list<std::string> init_list);

    public:
        void                     insert(std::string_view word);
        bool                     search(std::string_view word) const;
        bool                     starts_with(std::string_view prefix) const;
        void                     remove(std::string_view word);
        std::vector<std::string> get_all_words() const;

    private:
        bool      remove_helper(TrieNode* node, std::string_view, size_t depth);
        void      destroy_node(TrieNode* node);
        TrieNode* find_node(std::string_view prefix) const;
        void get_words_from_node(TrieNode* node, std::string current_prefix, std::vector<std::string>& words) const;

    private:
        TrieNode* m_root;

    }; // class Trie

} // namespace my

#endif // __TRIE_TREE_INCLUDE_TRIE_TREE_H__
