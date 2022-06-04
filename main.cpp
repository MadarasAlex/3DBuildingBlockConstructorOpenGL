#include "Quads.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int currentX, currentY, currentZ;
int currentQuadsNumber;
int dimension;

static void initCube();
static void drawSurface();
static void init();
static void keyboard(unsigned char k, int x, int y);
static void mouse(int button, int state, int x, int y);
static void display();
static void addQuads();
static void drawQuads();
static void mouseMove(int x, int y);
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    dimension = 40;
    glutCreateWindow("3D Block Constructor");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
static void initCube()
{
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(currentX, currentY, currentZ);
    glutSolidCube(0.4);
    glPopMatrix();
}
static void drawSurface()
{
    for (int i = 0; i < dimension; i++)
    {
        glPushMatrix();
        if (i < dimension / 2)
            glTranslatef(0, 0, i);
        else
        {
            glTranslatef(i - (dimension / 2), 0, 0);
            glRotatef(-90, 0, 1, 0);
        }
        glBegin(GL_LINES);
        glVertex3f(0, -0.2, 0);
        glVertex3f((dimension / 2) - 1, -0.1, 0);
        glEnd();
        glPopMatrix();
    }
    glColor3f(1, 1, 1);
    glLineWidth(1);
}
static void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40, 1.0f, 0.1f, 1000);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
}
static void keyboard(unsigned char k, int x, int y)
{
    switch (k)
    {
    case 'w':
        if (currentZ >= 1)
            currentZ -= 1;
        break;
    case 's':
        if (currentZ < (dimension / 2) - 1)
        {
            //   cout << currentZ << endl;
            currentZ += 1;
        }
        break;
    case 'a':
        if (currentX >= 1)
            currentX -= 1;
        break;
    case 'd':
        if (currentX < (dimension / 2) - 1)
            currentX += 1;
        break;
    case 'z':
        if (currentY >= 1)
            currentY -= 1;
        break;
    case 'q':
        if (currentY < (dimension / 2) - 1)
            currentY += 1;
        break;
    case 32:
        addQuads();
        break;
    case 'r':
        Q[currentQuadsNumber].red = 1;
        Q[currentQuadsNumber].green = 0;
        Q[currentQuadsNumber].blue = 0;
        break;
    case 'g':
        Q[currentQuadsNumber].red = 0;
        Q[currentQuadsNumber].green = 1;
        Q[currentQuadsNumber].blue = 0;
        break;
    case 'b':
        Q[currentQuadsNumber].red = 0;
        Q[currentQuadsNumber].green = 0;
        Q[currentQuadsNumber].blue = 1;
        break;
    case 'y':
        Q[currentQuadsNumber].red = 0.8;
        Q[currentQuadsNumber].green = 1;
        Q[currentQuadsNumber].blue = 0.1;
        break;
    case 'p':
        Q[currentQuadsNumber].red = 0.9;
        Q[currentQuadsNumber].green = 0;
        Q[currentQuadsNumber].blue = 1;
        break;

    case 'o':
        Q[currentQuadsNumber].red = 0.9;
        Q[currentQuadsNumber].green = 0.5;
        Q[currentQuadsNumber].blue = 0;
        break;

    case 'l':
        Q[currentQuadsNumber].red = 1;
        Q[currentQuadsNumber].green = 1;
        Q[currentQuadsNumber].blue = 1;
        break;
    }
    glutPostRedisplay();
}
static void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON)
    {
        exit(0);
    }
}

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-13, 0, -45);
    glRotatef(30, 1, 1, 0);
    drawSurface();
    drawQuads();
    initCube();
    glutSwapBuffers();
}
static void addQuads()
{
    Q[0].state++;
    if (Q[0].state > 4)
    {
        Q[0].state = 1;
    }
    int initialState = Q[0].state;
    if (initialState == 1)
    {
        Q[0].total++;
        currentQuadsNumber = Q[0].total;
    }
    if (initialState == 1)
    {
        Q[currentQuadsNumber].x1 = currentX;
        Q[currentQuadsNumber].y1 = currentY;
        Q[currentQuadsNumber].z1 = currentZ;
    }
    if (initialState == 1 || initialState == 2)
    {
        Q[currentQuadsNumber].x2 = currentX;
        Q[currentQuadsNumber].y2 = currentY;
        Q[currentQuadsNumber].z2 = currentZ;
    }
    if (initialState == 1 || initialState == 2 || initialState == 3)
    {
        Q[currentQuadsNumber].x3 = currentX;
        Q[currentQuadsNumber].y3 = currentY;
        Q[currentQuadsNumber].z3 = currentZ;
    }
    if (initialState == 1 || initialState == 2 || initialState == 3 || initialState == 4)
    {
        Q[currentQuadsNumber].x4 = currentX;
        Q[currentQuadsNumber].y4 = currentY;
        Q[currentQuadsNumber].z4 = currentZ;
    }
}
static void drawQuads()
{
    for (int i = 1; i < Q[0].total + 1; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(Q[i].red, Q[i].green, Q[i].blue);
        glVertex3f(Q[i].x1, Q[i].y1, Q[i].z1);
        glVertex3f(Q[i].x2, Q[i].y2, Q[i].z2);
        glVertex3f(Q[i].x3, Q[i].y3, Q[i].z3);
        glVertex3f(Q[i].x4, Q[i].y4, Q[i].z4);
        glEnd();
    }
}
