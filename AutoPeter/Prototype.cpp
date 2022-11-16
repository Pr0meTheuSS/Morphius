/* Copyright 2022 <Olimpiev Y.> */
#include <GL/glut.h>

#include <valarray>
#include <cmath>

#include "GraphRepr/GraphRepr.hpp"

void DrawPoligon(const std::valarray<float>* v, size_t amount) {
    glBegin(GL_POLYGON);
    for (size_t i = 0; i < amount; i++) {
        glVertex2f(v[i][0], v[i][1]);
    }
    glEnd();
}


void DrawCircle(const std::valarray<float>& center, float radius, unsigned int granularity = 32) {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for(unsigned int step = 0; step < granularity; step++) {
        float theta = 2.0f * M_PI * float(step) / float(granularity);  // get the current angle

        float dx = radius * cosf(theta);  // calculate the x component
        float dy = radius * sinf(theta);  // calculate the y component

        glVertex2f(center[0] + dx, center[1] + dy);//output vertex
    }
    glEnd();
}

void DrawGraph(const GraphRepresentation& graph) {
    for (size_t node = 0; node < graph.GetSize(); node++) {
        DrawCircle(graph.GetPosition(node), 0.03f);
    }
    for (size_t node1 = 0; node1 < graph.GetSize(); node1++) {
        for (size_t node2 = 0; node2 < graph.GetSize(); node2++) {
            if (graph.GetEdge({node1, node2})) {
                // Draw line from node1 to node2
                // TODO: implement
            }
        }
    }
}
    // Init edges list and nodes amount.
    const std::pair<size_t, size_t> peterGraphEdges[] = { {0,1}, {0,5},{0,4}, {1,2}, {1,6}, {2,3}, {2,7}, {3,4}, {3,8}, {4,9}, {5,7}, {5,8}, {6,8}, {6,9}, {7,9} };
    const size_t peterGraphNodesAmount = 10;
GraphRepresentation peterGraphRepr(10);


void displayloop() {
   // Init graph's nodes positions.
    //  ...
    float radius = 0.3;
    for (size_t node = 0; node < peterGraphRepr.GetSize(); node++) {
        float theta = 2.0f * M_PI * float(node) / float(peterGraphRepr.GetSize()) + M_PI / 2.0f;  // get the current angle
        int radScale = node / (peterGraphRepr.GetSize() / 2);
        float x = radius * (radScale + 1) * cosf(theta);  // calculate the x component
        float y = radius * (radScale + 1) * sinf(theta);  // calculate the y component
        peterGraphRepr.SetPosition(node, {x, y});
    }

    glClear(GL_COLOR_BUFFER_BIT);
    DrawGraph(peterGraphRepr);
    glFlush();
}
int main(int argc, char** argv) {
    // Init graph representation.
    for (size_t node = 0; node < sizeof(peterGraphEdges)/sizeof(peterGraphEdges[0]); node++) {
        peterGraphRepr.AddEdge(peterGraphEdges[node]);
    }
    
 
    // Graphics part init and run main loop.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("AutoPeter");

    glutDisplayFunc(displayloop);
    glutMainLoop();

    return EXIT_SUCCESS;
}

