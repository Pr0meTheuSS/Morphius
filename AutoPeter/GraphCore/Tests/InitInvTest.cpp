#include <gtest/gtest.h>
#include "../GraphCore.hpp"

TEST(GraphCoreTest, InitInvariantTest) {
    // INIT
    size_t graphSize = 10;
    GraphCore gr(graphSize);
    
    // CHECK DAFAULT ADJACENCY MATRIX INIT VALUES
    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            EXPECT_EQ(gr.GetEdge({begin, end}), false);
        }
    }
}

