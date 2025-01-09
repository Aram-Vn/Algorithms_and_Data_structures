
#include <TrieTree.h>
#include <algorithm>
#include <gtest/gtest.h>

namespace {

    class TrieTest : public ::testing::Test
    {
    protected:
        my::Trie trie;

        void SetUp() override
        {
            trie.insert("hello");
            trie.insert("world");
            trie.insert("help");
            trie.insert("helium");
        }
    };

    TEST_F(TrieTest, InsertAndSearch)
    {
        EXPECT_TRUE(trie.search("hello"));
        EXPECT_TRUE(trie.search("world"));
        EXPECT_FALSE(trie.search("hell")); // Partial match
        EXPECT_FALSE(trie.search("hero")); // Non-existing word
    }

    TEST_F(TrieTest, StartsWith)
    {
        EXPECT_TRUE(trie.starts_with("hel"));
        EXPECT_TRUE(trie.starts_with("wor"));
        EXPECT_FALSE(trie.starts_with("her")); // Non-existing prefix
    }

    TEST_F(TrieTest, RemoveWord)
    {
        EXPECT_TRUE(trie.search("hello"));
        trie.remove("hello");
        EXPECT_FALSE(trie.search("hello"));
        EXPECT_TRUE(trie.search("help")); // Ensure other words are unaffected
    }

    TEST_F(TrieTest, GetAllWords)
    {
        std::vector<std::string> words = trie.get_all_words();
        EXPECT_NE(std::find(words.begin(), words.end(), "hello"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "world"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "help"), words.end());
        EXPECT_NE(std::find(words.begin(), words.end(), "helium"), words.end());
    }

} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
