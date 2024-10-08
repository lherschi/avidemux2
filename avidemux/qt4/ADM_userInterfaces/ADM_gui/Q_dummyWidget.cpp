
#include "config.h"
#ifdef USE_OPENGL
#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif
#include <QOpenGLWidget>
#if (defined(ADM_CPU_ARMEL) || defined(ADM_CPU_ARM64)) && !defined(__APPLE__)
  #include "GL/gl.h" // not included via QOpenGLWidget on ES2 platforms
#endif
#include "Q_dummyWidget.h"
#include "ADM_default.h"

void dummyGLWidget::paintGL()
{
    ADM_info("Painting dummy openGl widget\n");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}
dummyGLWidget::dummyGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}
dummyGLWidget::~dummyGLWidget()
{

}
void dummyGLWidget::initializeGL()
{
    ADM_info("Initializing dummy openGl widget\n");
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_CULL_FACE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPushMatrix(); // push to avoid stack underflow in the first paintGL() call
};
#endif
