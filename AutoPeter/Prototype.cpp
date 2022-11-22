/* Copyright 2022 <Olimpiev Y.> */
#include <GL/glut.h>

#include <iostream>
#include <valarray>
#include <cmath>
#include <cassert>

#include "GraphRepr/GraphRepr.hpp"

/*
 * Peter Automorphism function:
 *      version 1:
 *          0 -> 5
 *          1 -> 8
 *          2 -> 9
 *          3 -> 6
 *          4 -> 8
 *          5 -> 0
 *          6 -> 2
 *          7 -> 4
 *          8 -> 1 
 *          9 -> 3
 */      size_t PeterGraphAutoMorphVer1(size_t index) {
           assert(index < 10);
           switch(index) {
               case 0: return 5;
               case 1: return 8;
               case 2: return 9;
               case 3: return 6;
               case 4: return 7;
               case 5: return 0;
               case 6: return 2;
               case 7: return 4;
               case 8: return 1;
               case 9: return 3;
               default: return 0; 
           }
       }
 /*      version 2:
 *          0 -> 8
 *          1 -> 5
 *          2 -> 7
 *          3 -> 9
 *          4 -> 6
 *          5 -> 1
 *          6 -> 3
 *          7 -> 0
 *          8 -> 2
 *          9 -> 4
 */      size_t PeterGraphAutoMorphVer2(size_t index) {
           assert(index < 10);
           switch(index) {
               case 0: return 8;
               case 1: return 5;
               case 2: return 7;
               case 3: return 9;
               case 4: return 6;
               case 5: return 1;
               case 6: return 3;
               case 7: return 0;
               case 8: return 2;
               case 9: return 4;
               default: return 0;
           }
       }

size_t PterGraphInternalCircleRightTurn(size_t index) {
    assert(index < 10);
    switch(index) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 6;
        case 6: return 7;
        case 7: return 8;
        case 8: return 9;
        case 9: return 5;
        default: return 0;
    }
}

size_t PterGraphExternalCircleRightTurn(size_t index) {
    assert(index < 10);
    switch(index) {
        case 0: return 1;
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 0;
        case 5: return 5;
        case 6: return 6;
        case 7: return 7;
        case 8: return 8;
        case 9: return 9;
        default: return 0;
    }
}

//void ViewApplyAutomorphism(GraphRepresentation* graph, std::function<size_t(size_t)> MapNodes, size_t detalization = 10) {
//    assert(graph);
//    GraphRepresentation staticOrigGraph(*graph);  
//}

// Init edges list and nodes amount.
const std::pair<size_t, size_t> peterGraphEdges[] = { {0,1}, {0,5},{0,4}, {1,2}, {1,6}, {2,3}, {2,7}, {3,4}, {3,8}, {4,9}, {5,7}, {5,8}, {6,8}, {6,9}, {7,9} };

GraphRepresentation peterGraphRepr(10);
GraphRepresentation staticOrigGraph(10);

void AutoMorphismCalcStep(GraphRepresentation* graph, size_t detalization = 10) {
    for (size_t node = 0; node < graph->GetSize(); node++) {    
        std::valarray<float> move = staticOrigGraph.GetPosition(PterGraphInternalCircleRightTurn(node)) - graph->GetPosition(node);
        move /= detalization;
        graph->SetPosition(node, graph->GetPosition(node) + move);
    }
}

void DrawCircle(const std::valarray<float>& center, float radius, unsigned int granularity = 32) {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for(unsigned int step = 0; step < granularity; step++) {
        float theta = 2.0f * M_PI * float(step) / float(granularity);

        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);

        glVertex2f(center[0] + dx, center[1] + dy);
    }
    glEnd();
}

void DrawLine(const std::valarray<float>& begin, const std::valarray<float>& end) {
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(begin[0], begin[1]);
    glVertex2f(end[0], end[1]);
    glEnd();
}



void InitPeterGraph(GraphRepresentation* graph) {
    // Init graph representation.
    for (size_t node = 0; node < sizeof(peterGraphEdges) / sizeof(peterGraphEdges[0]); node++) {
        peterGraphRepr.AddEdge(peterGraphEdges[node]);
    }
    // Init graph's nodes positions.
    float radius = 0.3;
    // Init external circle
    for (size_t node = 0; node < graph->GetSize() / 2; node++) { 
        float theta = -2.0f * M_PI * float(node) / float(graph->GetSize() / 2) + M_PI / 2.0f;
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        graph->SetPosition(node, {x, y});
    // Init internal circle
    for (size_t node = graph->GetSize() / 2; node < graph->GetSize(); node++) {
        float theta = -2.0f * M_PI * float(node) / float(graph->GetSize() / 2) + M_PI / 2.0f;
        float x = radius / 2.0f * cosf(theta);
        float y = radius / 2.0f * sinf(theta);
        graph->SetPosition(node, {x, y});
    }
}

void displayloop() {
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGraph(peterGraphRepr);
    glutSwapBuffers();
}

void timer(int x) {
    std::cout << "timer called" << std::endl;
    AutoMorphismCalcStep(&peterGraphRepr);
    displayloop();
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv) {
    InitPeterGraph(&peterGraphRepr);
    InitPeterGraph(&staticOrigGraph);
    // Graphics part init and run main loop.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("AutoPeter");
    
    glutTimerFunc(1000, timer, 0);
    // glutDisplayFunc(displayloop);
    glutMainLoop();

    return EXIT_SUCCESS;
}

