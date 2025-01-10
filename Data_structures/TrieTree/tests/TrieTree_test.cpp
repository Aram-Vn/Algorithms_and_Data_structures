#include <TrieTree.h>
#include <algorithm>
#include <gtest/gtest.h>

namespace {

    class TrieTest : public ::testing::Test
    {
    protected:
        my::Trie trie;
        my::Trie trie_init_list = { "hello", "world", "trie", "tree", "test" };

        void SetUp() override
        {
            trie.insert("hello");
            trie.insert("world");
            trie.insert("help");
            trie.insert("helium");
        }
    };

    // Test for inserting and searching words
    TEST_F(TrieTest, InsertAndSearch)
    {
        EXPECT_TRUE(trie.search("hello"));
        EXPECT_TRUE(trie.search("world"));
        EXPECT_FALSE(trie.search("hell"));
        EXPECT_FALSE(trie.search("hero"));
    }

    // Test for checking words that start with a specific prefix
    TEST_F(TrieTest, StartsWith)
    {
        EXPECT_TRUE(trie.starts_with("hel"));
        EXPECT_TRUE(trie.starts_with("wor"));
        EXPECT_FALSE(trie.starts_with("her"));
    }

    // Test for removing a word from the trie
    TEST_F(TrieTest, RemoveWord)
    {
        EXPECT_TRUE(trie.search("hello"));
        trie.remove("hello");
        EXPECT_FALSE(trie.search("hello"));
        EXPECT_TRUE(trie.search("help"));
    }

    // Test for retrieving all words from the trie
    TEST_F(TrieTest, GetAllWords)
    {
        std::vector<std::string> words = trie.get_all_words();
        EXPECT_NE(std::find(words.begin(), words.end(), "hello"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "world"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "help"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "helium"), words.end());
    }

    // Test for initializing Trie with an initializer list
    TEST_F(TrieTest, InsertAndSearch_init_list)
    {
        my::Trie trie = { "hello", "world", "trie", "tree", "test" };

        EXPECT_TRUE(trie_init_list.search("hello"));
        EXPECT_TRUE(trie_init_list.search("world"));
        EXPECT_TRUE(trie_init_list.search("trie"));
        EXPECT_TRUE(trie_init_list.search("tree"));
        EXPECT_TRUE(trie_init_list.search("test"));
        EXPECT_FALSE(trie_init_list.search("nonexistent"));
    }

    // Test for checking words that start with a prefix using initializer list
    TEST_F(TrieTest, StartsWith_init_list)
    {
        my::Trie trie = { "hello", "world", "trie", "tree", "test" };

        EXPECT_TRUE(trie_init_list.starts_with("he"));
        EXPECT_TRUE(trie_init_list.starts_with("wo"));
        EXPECT_TRUE(trie_init_list.starts_with("tri"));
        EXPECT_TRUE(trie_init_list.starts_with("tre"));
        EXPECT_TRUE(trie_init_list.starts_with("te"));
        EXPECT_FALSE(trie_init_list.starts_with("non"));
    }

    // Test for removing a word with an initializer list
    TEST_F(TrieTest, RemoveWord_init_list)
    {
        my::Trie trie_init_list = { "hello", "world", "trie", "tree", "test" };

        EXPECT_TRUE(trie_init_list.search("test"));
        trie_init_list.remove("test");
        EXPECT_FALSE(trie_init_list.search("test"));
    }

    // Test for retrieving all words from a Trie initialized with an initializer list
    TEST_F(TrieTest, GetAllWords_init_list)
    {
        std::vector<std::string> words = trie_init_list.get_all_words();
        EXPECT_NE(std::find(words.begin(), words.end(), "hello"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "world"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "trie"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "tree"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "test"), words.end());
    }

} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
