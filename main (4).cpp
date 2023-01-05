#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<utility>
#include<cmath>


float step = 0;
float move = 0.025;
float edit_turn = 0.001;
float addx = 0;
float addy = 0;
float turn = 0;
float shiftTriangle = 5;
float shiftLeftTriangle = 1;

float carShift = 4;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);
    //164, 163, 173
    // moon
    glColor3f(164.0 / 255, 163.0 / 255, 173.0 / 255);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((2 * cos(angle)) - 6, (4 * sin(angle)) + 6);
    }
    glEnd();
    // ground
    glColor3f(60.0 / 255, 59.0 / 255, 64.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2f(-10, -2);
    glVertex2f(10, -2);

    glVertex2f(10, -2);
    glVertex2f(10, -10);

    glVertex2f(-10, -2);
    glVertex2f(-10, -10);

    glVertex2f(-10, -10);
    glVertex2f(10, -10);

    glEnd();
    //tringles

    glColor3f(209.0 / 255, 154.0 / 255, 71.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2f(-4 - shiftLeftTriangle, -2);
    glVertex2f(-2 - shiftLeftTriangle, 5);

    glVertex2f(-2 - shiftLeftTriangle, 5);
    glVertex2f(1 - shiftLeftTriangle, -2);

    glVertex2f(-4 - shiftLeftTriangle, -2);
    glVertex2f(1 - shiftLeftTriangle, -2);
    glEnd();

    glColor3f(209.0 / 255, 154.0 / 255, 71.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2f(-4 + shiftTriangle - shiftLeftTriangle, -2);
    glVertex2f(-2 + shiftTriangle - shiftLeftTriangle, 5);

    glVertex2f(-2 + shiftTriangle - shiftLeftTriangle, 5);
    glVertex2f(1 + shiftTriangle - shiftLeftTriangle, -2);

    glVertex2f(-4 + shiftTriangle - shiftLeftTriangle, -2);
    glVertex2f(1 + shiftTriangle - shiftLeftTriangle, -2);
    glEnd();

    glColor3f(209.0 / 255, 154.0 / 255, 71.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2f(-4 + shiftTriangle * 2 - shiftLeftTriangle, -2);
    glVertex2f(-2 + shiftTriangle * 2 - shiftLeftTriangle, 5);

    glVertex2f(-2 + shiftTriangle * 2 - shiftLeftTriangle, 5);
    glVertex2f(1 + shiftTriangle * 2 - shiftLeftTriangle, -2);

    glVertex2f(-4 + shiftTriangle * 2 - shiftLeftTriangle, -2);
    glVertex2f(1 + shiftTriangle * 2 - shiftLeftTriangle, -2);
    glEnd();

    //car bottom
    glColor3f(227.0 / 255, 207.0 / 255, 109.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2d(-5 + step - carShift, -5);
    glVertex2d(4 + step - carShift, -5);

    glVertex2d(-5 + step - carShift, -5);
    glVertex2d(-5 + step - carShift, -7);

    glVertex2d(4 + step - carShift, -5);
    glVertex2d(4 + step - carShift, -7);

    glVertex2d(-5 + step - carShift, -7);
    glVertex2d(4 + step - carShift, -7);

    glEnd();

    //car top

    glColor3f(227.0 / 255, 207.0 / 255, 109.0 / 255);
    glBegin(GL_POLYGON);

    glVertex2d(-2 + step - carShift, -3);
    glVertex2d(2 + step - carShift, -3);

    glVertex2d(-2 + step - carShift, -3);
    glVertex2d(-2 + step - carShift, -5);

    glVertex2d(2 + step - carShift, -3);
    glVertex2d(2 + step - carShift, -5);

    glVertex2d(2 + step - carShift, -5);
    glVertex2d(-2 + step - carShift, -5);

    glEnd();

    // wheels
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((1 * cos(angle)) - 2 + step - carShift, (2 * sin(angle)) - 8);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++) {
        double angle = i * 3.14 / 180;
        glVertex2f((1 * cos(angle)) + 2 + step - carShift, (2 * sin(angle)) - 8);
    }
    glEnd();

    //wheel line
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);

    glVertex2d(-3 + step, -8);
    glVertex2d(-1 + step, -8);

    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);

    glVertex2d(-3 + step - 4, -8);
    glVertex2d(-1 + step - 4, -8);

    glEnd();
    glFlush();
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    step += move;
    if (step > 10 || step < 0) {
        move = -move;
    }
    turn += edit_turn;
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200, 800);

    glutCreateWindow("Hossam Shiha 20109088 Pola Ashraf 20102166");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glClearColor(0, 0, 0, 1.0);

    glutMainLoop();
}
