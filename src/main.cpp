#include <iostream>
#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("testing");

    glutDisplayFunc(display);
    glutMainLoop();

    

    return 0;
}