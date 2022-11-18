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

void SetAutomorph(const GraphRepresentation& graph1, const GraphRepresentation& graph2) {
    assert(graph1.GetSize() == graph2.GetSize());
    
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

void DrawGraph(const GraphRepresentation& graph) {
    for (size_t node = 0; node < graph.GetSize(); node++) {
        DrawCircle(graph.GetPosition(node), 0.03f);
    }
    // Replace to: for (auto edge: graph.Edges_) {DrawLine(edge.begin, edge.end)};
    for (size_t node1 = 0; node1 < graph.GetSize(); node1++) {
        for (size_t node2 = 0; node2 < graph.GetSize(); node2++) {
            if (graph.GetEdge({node1, node2})) {
                DrawLine(graph.GetPosition(node1), graph.GetPosition(node2));
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
    float radius = 0.3;
    // Init external circle
    for (size_t node = 0; node < peterGraphRepr.GetSize() / 2; node++) { 
        float theta = 2.0f * M_PI * float(node) / float(peterGraphRepr.GetSize() / 2) + M_PI / 2.0f;

        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        peterGraphRepr.SetPosition(node, {x, y});
    }
    // Init internal circle
    for (size_t node = peterGraphRepr.GetSize() / 2; node < peterGraphRepr.GetSize(); node++) {
        float theta = 2.0f * M_PI * float(node) / float(peterGraphRepr.GetSize() / 2) + M_PI / 2.0f;

        float x = radius / 2.0f * cosf(theta);
        float y = radius / 2.0f * sinf(theta);
        peterGraphRepr.SetPosition(node, {x, y});
    }

    glClear(GL_COLOR_BUFFER_BIT);
    DrawGraph(peterGraphRepr);
    glFlush();
}

int main(int argc, char** argv) {
    // Init graph representation.
    for (size_t node = 0; node < sizeof(peterGraphEdges) / sizeof(peterGraphEdges[0]); node++) {
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

