#include <gtest/gtest.h>
#include "../GraphCore.hpp"

TEST(GraphCoreTest, AddEdgeTest) {
    // INIT
    size_t graphSize = 10;
    GraphCore gr(graphSize);
    
    // ADD EDGES BETWEEN EVEN NODES AND CHECK THEM
    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            if (begin != end && begin % 2 == 0 && end % 2 == 0) {
                gr.AddEdge({begin, end});
                EXPECT_EQ(gr.GetEdge({begin, end}), true);
            } else {
                EXPECT_EQ(gr.GetEdge({begin, end}), false);
            }
        }
    }
}

