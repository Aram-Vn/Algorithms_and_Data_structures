
#ifndef __TRIE_TREE_INCLUDE_TRIE_TREE_H__
#define __TRIE_TREE_INCLUDE_TRIE_TREE_H__

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
            ~TrieNode()
            {
                // Recursively delete all children
                for (auto& child : children)
                {
                    delete child.second;
                }
            }
        };

    public:
        Trie();  //
        ~Trie(); //

        void                     insert(const std::string& word);
        bool                     search(const std::string& word) const;
        bool                     starts_with(const std::string& prefix) const;
        void                     remove(const std::string& word);
        std::vector<std::string> get_all_words() const;

    private:
        bool remove_helper(TrieNode* node, const std::string& word, size_t depth);

        void      destroy_node(TrieNode* node);
        TrieNode* find_node(const std::string& prefix) const;

        void get_words_from_node(TrieNode* node, std::string current_prefix, std::vector<std::string>& words) const;

    private:
        TrieNode* m_root;

    }; // class Trie

} // namespace my

#endif // __TRIE_TREE_INCLUDE_TRIE_TREE_H__
