// includes for drawing

#include "../Models/GraphRepresentation.hpp"
#include "PrimitiveView.hpp"

void DrawGraph(const GraphRepresentation& graph) {
    for (size_t node1 = 0; node1 < graph.GetSize(); node1++) {
        DrawCircle(graph.GetPosition(node1), 0.03f);
        for (size_t node2 = 0; node2 < graph.GetSize(); node2++) {
            if (graph.GetEdge({node1, node2})) {
                DrawLine(graph.GetPosition(node1), graph.GetPosition(node2));
            }
        }
    }
}

