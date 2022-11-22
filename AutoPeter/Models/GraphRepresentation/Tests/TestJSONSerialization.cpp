#include "../GraphRepr.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

// Init edges list and nodes amount.
const std::pair<size_t, size_t> peterGraphEdges[] = { {0,1}, {0,5},{0,4}, {1,2}, {1,6}, {2,3}, {2,7}, {3,4}, {3,8}, {4,9}, {5,7}, {5,8}, {6,8}, {6,9}, {7,9} };

void InitPeterGraph(GraphRepresentation* graph) {
    // Init graph representation.
    for (size_t node = 0; node < sizeof(peterGraphEdges) / sizeof(peterGraphEdges[0]); node++) {
        graph->AddEdge(peterGraphEdges[node]);
    }
    // Init graph's nodes positions.
    float radius = 0.3;
    // Init external circle.
    for (size_t node = 0; node < graph->GetSize() / 2; node++) { 
        float theta = -2.0f * M_PI * float(node) / float(graph->GetSize() / 2) + M_PI / 2.0f;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        graph->SetPosition(node, {x, y});
    }
    // Init internal circle.
    for (size_t node = graph->GetSize() / 2; node < graph->GetSize(); node++) {
        float theta = -2.0f * M_PI * float(node) / float(graph->GetSize() / 2) + M_PI / 2.0f;
        float x = radius / 2.0f * cosf(theta);
        float y = radius / 2.0f * sinf(theta);
        graph->SetPosition(node, {x, y});
    }
}


int main(void) {
    // Init Petersen graph
    // and try to serialize it.
    GraphRepresentation peterGraphRepr(10);
    InitPeterGraph(&peterGraphRepr);
    std::fstream jsonFile;
    jsonFile.exceptions(std::ofstream::failbit);
    std::string jsonFileName = "graph.json";
    try {
        jsonFile.open(jsonFileName, std::ios::out);
        peterGraphRepr.SerializeJSON(jsonFile);
        jsonFile.close();
    }
    catch (const std::ostream::failure& e) {
        std::cerr << "Cannot handle this file:\t" + jsonFileName;
    }
    return EXIT_SUCCESS;
}
