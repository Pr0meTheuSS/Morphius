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

void DrawGraph(const GraphRepr& graph) {
    for (size_t node = 0; node < graph.Size(); node++) {
        DrawCircle({0.1f * node, 0.0f}, 0.3f);
    }
    for (size_t node1 = 0; node1 < graph.Size(); node1++) {
        for (size_t node2 = 0; node2 < graph.Size(); node2++) {
            if (graph.GetEdge({node1, node2})) {
                // Draw line from node1 to node2
                // TODO: implement
            }
        }
    }
}

void displayloop() {
    // Init edges list and nodes amount.
    const std::pair<size_t, size_t> peterGraphEdges[] = { {0,1}, {0,5},{0,4}, {1,2}, {1,6}, {2,3}, {2,7}, {3,4}, {3,8}, {4,9}, {5,7}, {5,8}, {6,8}, {6,9}, {7,9} };
    const size_t peterGraphNodesAmount = 10;

    // Init graph representation.
    GraphRepresentation peterGraphRepr(10);
    for (size_t node = 0; node < sizeof(petersenGraphEdges); node++) {
        peterGraphRepr.AddEdge(peterGraphEdges[node]);
    }
    
    // Init graph's nodes positions.
    //  ...


    glClear(GL_COLOR_BUFFER_BIT);
    DrawGraph(peterGraphRepr);
    glFlush();
}

int main(int argc, char** argv) {

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

