#ifndef AUTOPETER_GRAPHREPR_GRAPHREPR_HPP_
#define AUTOPETER_GRAPHREPR_GRAPHREPR_HPP_
#include <valarray>

#include "../GraphCore/GraphCore.hpp"

/*! \class info about class
 *  \details
 *  \author
 *  \data
 */
class GraphRepresentation {
 public:
    /*! \brief
     *  \details
     *  \param
     */
    explicit GraphRepresentation(size_t size = 0);
    
    /*! \brief
     *  \details
     *  \param
     */
    ~GraphRepresentation();

    /*! \brief
     *  \details
     *  \param
     */
    std::valarray<float> GetPosition(size_t nodeIndex) const;
    
    /*! \brief
     *  \details
     *  \param
     */
    void SetPosition(size_t nodeIndex, const std::valarray<float>& pos);
    
    /*! \brief
     *  \details
     *  \param
     */
    void AddEdge(const std::pair<size_t, size_t>& edge);
     
    /*! \brief
     *  \details
     *  \param
     */
    void RemoveEdge(const std::pair<size_t, size_t>& edge);

    /*! \brief
    *  \details
    *  \param
    */
    bool GetEdge(const std::pair<size_t, size_t>& edge) const;

    /*! \brief
     *  \details
     *  \param
     */
    size_t GetSize() const;
    GraphRepresentation(GraphRepresentation& other) : GraphCore_(other.GraphCore_), Size_(other.Size_) {
        Positions_ = new std::valarray<float>[Size_];
        for (size_t node = 0; node < Size_; node++) {
            Positions_[node] = other.Positions_[node];
        }
    }

 private:
    GraphCore GraphCore_;  /*! < field info */
    std::valarray<float>* Positions_;  /*! < field info */
    size_t Size_;  /*! < field info */
};

#endif  // AUTOPETER_GRAPHREPR_GRAPHREPR_HPP_
