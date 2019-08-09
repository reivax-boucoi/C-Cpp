#ifndef CURVEEDITOR_H
#define CURVEEDITOR_H

#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

class Node{
public:
    Node();
    Node(float x, float y);
    ~Node();
    void draw(void);
    float pos[2];
private:
};

class Path{
public:
    Path();
    ~Path();
    void draw(void);
private:
    vector<Node> v;
};
#endif
