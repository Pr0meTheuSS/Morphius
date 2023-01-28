/* Copyright 2023 Olimpiev Y. */
// Owner info.

// pragma guard.
#ifndef GRAPH_READER_HPP
#define GRAPH_READER_HPP

#include <fstream>
#include <iostream>
#include <stdexcept>

#include "GraphCore.hpp"

#include "jsoncpp/json/json.h"

/*!
 * TODO: rewrite after realisation and testing.
 *
 * class: Entity for reading GraphCore instance from text (.json) file.
 *        GraphJsonReader have to know about field "size" and need have garantees from 
 *        GraphCore - able to build GraphCore instance by container of edges ~  it is pair like (edge_start, edge_end).
 *        GraphJsonReader expects that JSON file contains fields:
 *          - "size" represents like integer value
 *          - "edges" represents like list of pairs looks like " "edges":[{"edge_start":number, "edge_end":number} , ... , {"edge_start":number, "edge_end":number} ]".
 */
class GraphJsonReader {
 public:
    GraphJsonReader() = delete;

    static GraphCore ReadGraphCoreFromJson(const std::string& filename) {
        std::ifstream in(filename);
        if (in.is_open()) {
            // Init json entities for reading json file with data for initializing GraphCore instance.
            Json::Value root;
            Json::CharReaderBuilder builder;
            JSONCPP_STRING errs;

            if (!parseFromStream(builder, in, &root, &errs)) {
                std::cerr << errs << std::endl;
                throw std::invalid_argument("Cannot read init json file for building GraphCore object.\n");
            }            
            // Test print. TODO: replace to real GraphCore building.
            // Note: able to inters by array (json list) by operator '[]'.
            std::cout << "Read graph's size is: " <<  root["edges"][1] << std::endl;
        } else {
            throw std::invalid_argument("Cannot read init json file for building GraphCore object.\n");
        }
        
        // Returns dumb.
        return GraphCore();
    }

    virtual ~GraphJsonReader() = default;
};

#endif // GRAPH_READER_HPP

