#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>

class GLWidget: public QOpenGLWidget
{
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL();
    void paintGL();
    void resizeGL(qint64 w, qint64 h);
    void reziseEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QOpenGLContext *_contextGL;
    QOpenGLFunctions *_functionsGL;
};

#endif // GLWIDGET_H
