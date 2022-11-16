#include "GraphRepr.hpp"

GraphRepresentation::GraphRepresentation(size_t size)
    : GraphCore_(size), Size_(size) {
    Positions_ = new std::valarray<float>[size];
}

GraphRepresentation::~GraphRepresentation() {
    delete [] Positions_;
    Size_ = 0ull;
}

std::valarray<float> GraphRepresentation::GetPosition(size_t nodeIndex) const {
     if (nodeIndex >= Size_) {
        throw std::invalid_argument("Invalid nodeIndex: out of range.\n");
    }
    return Positions_[nodeIndex];
}

void GraphRepresentation::SetPosition(size_t nodeIndex, const std::valarray<float>& pos) {
    if (nodeIndex >= Size_) {
        throw std::invalid_argument("Invalid nodeIndex: out of range.\n");
    }
    Positions_[nodeIndex] = pos;
}

void GraphRepresentation::AddEdge(const std::pair<size_t, size_t>& edge) {
    GraphCore_.AddEdge(edge);
}

void GraphRepresentation::RemoveEdge(const std::pair<size_t, size_t>& edge) {
    GraphCore_.RemoveEdge(edge);
}

bool GraphRepresentation::GetEdge(const std::pair<size_t, size_t>& edge) const {
    return GraphCore_.GetEdge(edge);
}

size_t GraphRepresentation::GetSize() const {
    return Size_;
}

