#include <iostream>
#include <ctime>
#include <cstdlib>
#include <GL/freeglut.h>

void display()
{

    //clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Set drawing color
    glColor3f(255.0f, 255.0f, 255.0f);

    // Draw points
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i)
    {
        int x = rand() % 100;
        std::cout << "x " << x << std::endl;
        glVertex2i(x, x);
    }
    glEnd();
    glFlush();
}

int main(int argc, char ** argv)
{
    srand((unsigned int) time(NULL));

    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("testing");


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0f, 400.0f, 0.0f, 400.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //======================================
    // sets the clear screen color to white
    //======================================
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    //=======================================
    // sets display() as the display function
    // for openGL
    //=======================================

    glutDisplayFunc(display);
    glutMainLoop();

    

    return 0;
}