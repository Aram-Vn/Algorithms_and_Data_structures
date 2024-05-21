#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <weighted_graph_adj_list.h>

// Utility function to capture the output of a function that prints to std::cout
std::string capture_stdout(const std::function<void()>& func)
{
    std::ostringstream buffer;
    std::streambuf*    old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST(weighted_graph_adj_listTest, AddVertexTest)
{
    my::weighted_graph g(3);
    EXPECT_NO_THROW(g.add_vertex());
    EXPECT_NO_THROW(g.add_edge(3, 1));
    EXPECT_ANY_THROW(g.add_edge(4, 1));
}

TEST(weighted_graph_adj_listTest, AddEdgeTest)
{
    my::weighted_graph g(5);
    EXPECT_NO_THROW(g.add_edge(0, 1));
    EXPECT_NO_THROW(g.add_edge(1, 2, 10));
    EXPECT_EQ(g.transpose()[1][0].second, 0);
    EXPECT_EQ(g.transpose()[2][0].second, 10);

    EXPECT_NO_THROW(g.add_edge(1, 2, 20));
    EXPECT_EQ(g.transpose()[2][0].second, 20);
}

TEST(weighted_graph_adj_listTest, DFSTest)
{
    my::weighted_graph g(5);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    std::string output = capture_stdout([&g] { g.dfs(0); });

    EXPECT_EQ(output, "0 1 2 3 4 \n");
}

TEST(weighted_graph_adj_listTest, BFSTest)
{
    my::weighted_graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);

    std::string output = capture_stdout([&g] { g.bfs(0); });

    EXPECT_EQ(output, "0 1 2 3 4 \n");
}

TEST(weighted_graph_adj_listTest, TransposeTest)
{
    my::weighted_graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);

    my::weighted_graph::AdjacencyList transposed = g.transpose();

    EXPECT_EQ(transposed[1].size(), 1);
    EXPECT_EQ(transposed[1][0].first, 0);
    EXPECT_EQ(transposed[2].size(), 1);
    EXPECT_EQ(transposed[2][0].first, 1);
}

TEST(weighted_graph_adj_listTest, KosarajuSCCTest)
{
    my::weighted_graph g(5);

    g.add_edge(0, 2);
    g.add_edge(2, 0);
    g.add_edge(1, 0);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    std::string output = capture_stdout([&g] { g.kosaraju_scc(); });

    EXPECT_NE(output.find("SCC: 3 "), std::string::npos);
    EXPECT_NE(output.find("SCC: 4 "), std::string::npos);
    EXPECT_NE(output.find("SCC: 0 1 2 "), std::string::npos);
}

TEST(weighted_graph_adj_listTest, TarjanSCCTest)
{
    my::weighted_graph g(5);

    g.add_edge(0, 2);
    g.add_edge(2, 0);
    g.add_edge(1, 0);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    std::string output = capture_stdout([&g] { g.tarjan_scc(); });

    EXPECT_NE(output.find("SCC: 4 "), std::string::npos);
    EXPECT_NE(output.find("SCC: 3 "), std::string::npos);
    EXPECT_NE(output.find("SCC: 1 2 0 "), std::string::npos);
}

TEST(weighted_graph_adj_listTest, PrintTest)
{
    my::weighted_graph g(3);

    g.add_edge(0, 1, 5);
    g.add_edge(1, 2, 10);

    std::string output = capture_stdout([&g] { g.print(); });

    EXPECT_NE(output.find("0 -> e:1 w:5"), std::string::npos);
    EXPECT_NE(output.find("1 -> e:2 w:10"), std::string::npos);
    EXPECT_NE(output.find("2 -> "), std::string::npos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
