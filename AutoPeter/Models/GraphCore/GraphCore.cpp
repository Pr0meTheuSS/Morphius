/* Copyright [2022] <Olimpiev Y.> */
#include "GraphCore.hpp"

GraphCore::GraphCore(size_t size) noexcept
: Size(size) {
     AdjMatrix = new bool* [size];
     for (size_t i = 0; i < size; i++) {
        AdjMatrix[i] = new bool;
     }
}

GraphCore::~GraphCore() {
    if (Size > 0) {
        for (size_t i = 0; i < Size; i++) {
            delete AdjMatrix[i];
        }
        delete [] AdjMatrix;
    }
}

bool GraphCore::VerifyEdge(const std::pair<size_t, size_t>& edge) const {
    return edge.first < Size && edge.second < Size;
}

bool GraphCore::GetEdge(const std::pair<size_t, size_t>& edge) const {
    if (!VerifyEdge(edge)) {
        throw std::out_of_range("From class :\tGraphCore\n"\
                                "From method :\t GetEdge\n"\
                                "Error :\t node index is out of range\n");
        return false;
    }
    return AdjMatrix[edge.first][edge.second];
}

void GraphCore::AddEdge(const std::pair<size_t, size_t>& edge) {
    if (!VerifyEdge(edge)) {
        throw std::out_of_range("From class :\tGraphCore\n"\
                                "From method :\t AddEdge\n"\
                                "Error :\t node index is out of range\n");
    }
    AdjMatrix[edge.first][edge.second] = true;
}

void GraphCore::RemoveEdge(const std::pair<size_t, size_t>& edge) {
     if (!VerifyEdge(edge)) {
        throw std::out_of_range("From class :\tGraphCore\n"\
                                "From method :\t RemoveEdge\n"\
                                "Error :\t node index is out of range\n");
    }
    // 0 will be converted to bool.
    // 0 is default value for marking unexisted edge.
    AdjMatrix[edge.first][edge.second] = 0;
}

GraphCore::GraphCore(GraphCore& other) {
    Size = other.Size;

    AdjMatrix = new bool*[Size];
    for (size_t node1 = 0; node1 < Size; node1++) {
        AdjMatrix[node1] = new bool[Size];
        for (size_t node2 = 0; node2 < Size; node2++) {
            AdjMatrix[node1][node2] = other.AdjMatrix[node1][node2];
        }
    }
}

size_t GraphCore::GetSize() const {
    return Size;
}

