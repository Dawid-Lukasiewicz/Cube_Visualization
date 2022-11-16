#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent)
{
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(4, 6);
    setFormat(format);

    _contextGL = new QOpenGLContext;
    _contextGL->setFormat(format);
    _contextGL->create();
    this->makeCurrent();
//    _contextGL->makeCurrent(());

    _functionsGL = _contextGL->functions();
}

void GLWidget::initializeGL()
{
    glClearColor(1, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5);
    glVertex2f(-0.5f, 0.5);
    glVertex2f(0.5f, -0.5);
    glVertex2f(0.5f, 0.5);

    glEnd();
    glFlush();
}

void GLWidget::resizeGL(qint64 w, qint64 h)
{

}

void GLWidget::reziseEvent(QResizeEvent *event)
{

}

void GLWidget::paintEvent(QPaintEvent *event)
{
    paintGL();
}
