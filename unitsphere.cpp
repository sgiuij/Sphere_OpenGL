#include "UnitSphere.h"

GLuint normBuffer;
GLuint posBuffer;
GLuint indexBuffer;
QOpenGLFunctions* s;

int slices, stacks;

#define PI 3.14159

void UnitSphere::createBuffers(QOpenGLFunctions *s, int slices, int stacks)
{
    ::s = s;
    ::slices = slices;
    ::stacks = stacks;
//    vector <float> positiondata;
//    vector <float> colordata;


    //initialize the buffers
    GLuint buffers[3];
    s->glGenBuffers(3, buffers);
    posBuffer = buffers[0];
    normBuffer = buffers[1];
    indexBuffer = buffers[2];

    vector<float> position;
    vector<float> normals;
    vector<unsigned short> indices;

    for (int i = 0; i <= stacks; i++) {
        float theta = i * PI / (float)stacks;
        float sinTheta = sinf(theta);
        float cosTheta = cosf(theta);

        for (int j = 0; j <= slices; j++) {
            float phi = j * 2 * PI / (float)slices;
            float sinPhi = sinf(phi);
            float cosPhi = cosf(phi);

            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;

            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);

            position.push_back(x);
            position.push_back(y);
            position.push_back(z);
        }
    }

    for (int i = 0; i < stacks; i++) {
        for (int j = 0; j < slices; j++) {
            unsigned short first = (i * (slices + 1)) + j;
            unsigned short second = first + slices + 1;

            indices.push_back(first);
            indices.push_back(second);
            indices.push_back(first + 1);

            indices.push_back(second);
            indices.push_back(second + 1);
            indices.push_back(first + 1);
        }
    }

    s->glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
    s->glBufferData(GL_ARRAY_BUFFER,
                    position.size() * sizeof(float),
                    &position[0],
            GL_STATIC_DRAW
                    );

    s->glBindBuffer(GL_ARRAY_BUFFER, normBuffer);
    s->glBufferData(GL_ARRAY_BUFFER,
                    normals.size() * sizeof(float),
                    &normals[0],
            GL_STATIC_DRAW);

    s->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    s->glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                    indices.size() * sizeof(unsigned short),
                    &indices[0],
            GL_STATIC_DRAW);
}

void UnitSphere::draw()
{
    s->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glDrawElements(GL_TRIANGLES, slices * stacks * 6, GL_UNSIGNED_SHORT, NULL);

}

void UnitSphere::freeBuffers()
{
    GLuint buffers[3] = {posBuffer, normBuffer, indexBuffer};
    s->glDeleteBuffers(3, buffers);
}

void UnitSphere::bindNormalBuffer()
{
    s->glBindBuffer(GL_ARRAY_BUFFER, normBuffer);
}

void UnitSphere::bindPositionBuffer()
{
    s->glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
}







// visual comment
