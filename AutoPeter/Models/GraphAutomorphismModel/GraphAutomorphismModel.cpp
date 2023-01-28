/* Copyright 2022 Olimpeiv Y. */

#include <functional>

#include "../GraphRepresentation/GraphRepresentation.hpp"

/*!
 *\brief Mapping node's index by automorphism function.
 *\param [in] graph is a const ref to graph representation to mapping.
 *\param [in] nodesMap is a const ref to function with signature size_t(size_t) to map curr_node_index -> new_node_index.
 *\returns new GraphRepresentation instance with updated nodes' positions.
 *\datails
 *\authors Olimpiev Y.
 *\date 21.11.2022
 */
GraphRepresentation AutomorphismModel(const GraphRepresentation& graph, const std::function<size_t(size_t)>& nodesMap) {
    // Copy graph structure.
    GraphRepresentation resultGraph = graph;
    // Update positions of nodes.
    for (size_t node = 0; node < graph.GetSize(); node++) {
        resultGraph.SetPosition(node, graph.GetPosition(NodesMap(node)));
    }
    return resultGraph;
}

