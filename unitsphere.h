#ifndef UNITSPHERE_H
#define UNITSPHERE_H

#include <QOpenGLFunctions>
#include <QGLWidget>
#include <QMatrix4x4>
#include <list>
#include <QOpenGLShaderProgram>

namespace UnitSphere
{

// Call this in initializeGL
// createBuffers(this, 50, 50);
// The slices and stacks are used to determine the number of vertices
// that define the sphere
void createBuffers(QOpenGLFunctions* s, int slices, int stacks);

// Call this somewhere in paintGL
void draw();

// Call this in your destructor
void freeBuffers();

// Call these when you need the position or normal
// buffer to be bound to the GL_ARRAY_BUFFER target
// (like when you want to set your attribute shader
// variables to use the positions and normals of
// the sphere)
void bindNormalBuffer();
void bindPositionBuffer();

vector <float> positiondata;
vector <float> colordata;

}

#endif // UNITSPHERE_H
