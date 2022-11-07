#include "GraphCore.hpp"

GraphCore::GraphCore(size_t size) 
 : Size(size) {
     AdjMatrix = new bool* [size];
     for (size_t i = 0; i < size; i++) {
        AdjMatrix[i] = new bool;
     }
}

GraphCore::~GraphCore() {
    for (size_t i = 0; i < Size; i++) {
        delete AdjMatrix[i];
    }
    delete [] AdjMatrix;
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
    // 0 will be converted to bool 
    // 0 is default value for marking unexisted edge
    AdjMatrix[edge.first][edge.second] = 0;
}

