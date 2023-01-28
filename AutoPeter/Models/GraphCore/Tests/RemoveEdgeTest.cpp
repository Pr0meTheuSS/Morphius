/* Copyright [2022] <Olimpiev Y.> */
#include <gtest/gtest.h>
#include "../GraphCore.hpp"

TEST(GraphCoreTest, RemoveEdgeTest) {
    // INIT
    const size_t graphSize = 10;
    GraphCore gr(graphSize);

    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            if (begin != end && begin % 2 == 0 && end % 2 == 0) {
                gr.AddEdge({begin, end});
            }
        }
    }

    // REMOVE ALL EDGES
    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            if (gr.GetEdge({begin, end})) {
                gr.RemoveEdge({begin, end});
            }
        }
    }

    // EXPECT GRAPH WILL BE EQL EMPTY GRAPH
    GraphCore emptyGr(graphSize);
    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            EXPECT_EQ(gr.GetEdge({begin, end}), emptyGr.GetEdge({begin, end}));
        }
    }
}

