/* Copyright 2023 Olimpiev Y. */
// Owner info.

// pragma guard.
#ifndef GRAPH_JSON_READER_HPP
#define GRAPH_JSON_READER_HPP

#include <cassert>              // for asserts.
#include <fstream>              // for file reading.
#include <iostream>             // for writing into std::cerr.
#include <stdexcept>            // for std::exception (std::invalid_argument).

#include "GraphCore.hpp"        // for instance GraphCore.
#include "jsoncpp/json/json.h"  // for parsing json.

/*!
 * \class: Entity for reading GraphCore instance from text (.json) file.
 *        GraphJsonReader have to know about field "size" and need have garantees from GraphCore.
 *        GraphCore - able to build GraphCore instance by container of edges ~  it is pair like {begin, end}.
 *        GraphJsonReader expects that JSON file contains fields:
 *          - "size" represents like integer value
 *          - "edges" represents like list of pairs looks like " "edges": [{"begin": number, "end":number} , ... , {"begin":number, "end":number} ]".
 *      
 *      json file examle:
 * {
 *   "size": 5,
 *   "edges": [
 *       {
 *           "begin": 0, 
 *           "end": 1
 *       },
 *       {
 *           "begin": 1, 
 *           "end": 2
 *       },
 *       {
 *           "begin": 2, 
 *           "end": 3
 *       },
 *       {
 *           "begin": 3, 
 *           "end": 4
 *       },
 *       {
 *           "begin": 4, 
 *           "end": 0
 *       }
 *   ]
 * }
 *
 */

class GraphJsonReader {
 public:
    // Deleted default ctor - there is no neccessery to instance smth.
    GraphJsonReader() = delete;
    // Method for instancing GraphCore object by json file with getted name.
    // Could throw std::invalid_argument.
    // returns GraphCore instance in case successfully json parsing, default instance of GraphCore in other cases (may be useless).
    static GraphCore ReadGraphCoreFromJson(const std::string& filename) {
        // Open filestream by getted filename.
        std::ifstream in(filename);
        
        if (in.is_open()) {
            // Init json entities for reading json file with data for initializing GraphCore instance.
            Json::Value root;
            Json::CharReaderBuilder builder;
            JSONCPP_STRING errs;
            // If data was not successfully read.
            if (!parseFromStream(builder, in, &root, &errs)) {
                // Print errors of json parser into std::cerr.
                std::cerr << errs << std::endl;
                // Throw an exception, need to catch it. TODO: catch exception.
                throw std::invalid_argument("Cannot read init json file for building GraphCore object.\n");
            }
            // String 'root["size"].asLargestInt()' converts field 'size' to largest unsigned int value (uint or uint64).
            // Expect getted size field is equal size of edges' list.
            assert(root["size"].asLargestInt() == root["edges"].size());
            // Init GraphCore instance with size = root["edges"].size(). 
            GraphCore retGraphCore(root["edges"].size());
            // Foreach edge in json file get begin and end of edge and add it into retGraphCore.
            for (auto edge: root["edges"]) {
                retGraphCore.AddEdge({edge["begin"].asLargestInt(), edge["end"].asLargestInt()});
            }
            // Return built GraphCore.
            return retGraphCore;
        } else {
            // Throw exception if file was not opened. TODO: catch exception.
            throw std::invalid_argument("Cannot read init json file for building GraphCore object.\n");
        }
        // Returns empty GraphCore by default.
        return GraphCore();
    }

    virtual ~GraphJsonReader() = default;
};

#endif // GRAPH__JSON_READER_HPP

