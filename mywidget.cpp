#include "mywidget.h"

mywidget::mywidget(QWidget *parent) :
    QGLWidget(parent)
{

}


void mywidget::initializeGL()
{
    glClearColor(0.5,0.0,0.0,1.0);
    //shaderprogram +data
}

void mywidget::resizeGL(int w, int h)
{
    //projection
    glViewport(0,0,w,h);//widthlong hight tall
}

void mywidget::PaintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

//void mywidget::keyPressEvent(QKeyEvent *)
//{
    //ex. Ctrl+P etc.
    //
//}

//void mywidget::timerEvent(QTimerEvent*)
//{
    //timing
//}


