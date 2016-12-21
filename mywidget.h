#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <list>
#include <QOpenGLShaderProgram>

class mywidget : public QGLWidget, protected QOPenGLFunctions
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = 0);

     //QGLWidge interface
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
signals:
    
public slots:


    //QWidget interface
protected:
    void keyPressEvent(QKeyEvent *);

    //QObject interface
protected:
    void timerEvent(QTimerEvent *);
    
private:
    //location of shader variables
//    GLuint posBuffer, colorBufferl;
//    GLuint posAttributs, colorAttribute;
    GLuint matrixUniform;

//    QMatrix4X4 perspective;
//    QMatrix4X4 modelview;
//    list<QMatrix4X4> mvStack;

};

#endif // MYWIDGET_H
