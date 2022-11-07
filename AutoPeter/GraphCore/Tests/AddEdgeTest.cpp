#include <gtest/gtest.h>
#include "../GraphCore.hpp"

TEST(GraphCoreTest, InitInvariantTest) {
    // INIT
    size_t graphSize = 10;
    GraphCore gr(graphSize);
    
    // ADD EDGES BETWEEN EVEN NODES AND CHECK THEM
    for (size_t begin = 0; begin < graphSize; begin++) {
        for (size_t end = 0; end < graphSize; end++) {
            if (begin != end && begin % 2 == 0 && end % 2 == 0) {
                gr.AddEdge({begin, end});
                EXRECT_EQ(gr.GetEdge({begin, end}), true);
            } else {
                EXRECT_EQ(gr.GetEdge({begin, end}), false);
            }
        }
    }
}

