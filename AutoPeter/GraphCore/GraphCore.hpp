// Owner info 

// include guard
#ifndef GRAPH_CORE_HPP
#define GRAPH_CORE_HPP

#include <utility>      // For std::pair
#include <cstdlib>      // For std::size_t
#include <stdexcept>    // For std::out_of_range 

/*!
 * \class
 * \brief Implementation of graph core logic for
 *      unordered unweight graphs
 *      with immutable size
 * \details Node numbering starts from zero.
 * \version 1.0.0
 * \author Prometheus
 * \date 05.11.2022
 */
class GraphCore {
public:
    /*! Docs
     *\brief Deleted standard constructor for immutability of graph size.
     */
    GraphCore() = delete;
    
    /*! Docs
     *\brief Explicit GraphCore constructor.
     *\details Allocate memory by new operator for second-orfer matrix.
     *\param [in] size Graph size. Equal nodes amount.
     */
    explicit GraphCore(const size_t size);
    
    /*! Docs
     *\brief GraphCore destructor. 
     *\details Call delete and delete [] operators to deallocate memory.
     */
    ~GraphCore();
    
    /*! Docs
     *\brief Edge getter.
     *\param [in] edge pair of indexes == {edge_begin, edge_end}.
     *\returns true if the graph contains an edge with the specified begin and end, false - otherwise
     *\throw std::out_of_range if the node is accessed by an invalid index.
    */

    bool GetEdge(const std::pair<size_t, size_t>& edge) const;
    
    /*! Docs
     *\brief Edge setter.
     *\param [in] edge pair of indexes == {edge_begin, edge_end}.
     *\returns void
     *\throw std::out_of_range if the node is accessed by an invalid index.
     */
    void SetEdge(const std::pair<size_t, size_t>& edge) const ;
    
    /*! Docs
     *\brief Size getter.
     *\returns Graph's size. Equal nodes amount.
     */
    size_t GetSize();
private:
    bool VerifyEdge(const std::pair<size_t, size_t>& edge) const; 
    bool** AdjMatrix; /*! <Second-order array of bools*/
    size_t Size; /*! <Graph's size == node's amount*/
};

#endif

