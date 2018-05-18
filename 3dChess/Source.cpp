#include<windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
float _angle = 0;
float i;
int k = 0;
GLuint list_blackArea;
GLuint list_whiteArea;
GLuint list_leftPieces;

void handleKeypress(unsigned char key, int x, int y)
{
}

void drawLeftPieces() {

	//1st piramid
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.5, 0.3, 0);
	glVertex3f(0, 0.3, 0);
	glVertex3f(0, 0.3, -1.4);
	glVertex3f(1.5, 0.3, -1.4);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.5, 0.3, 0);
	glVertex3f(0.7, 1.3, -0.7);
	glVertex3f(0, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.5, 0.3, 0);
	glVertex3f(0.7, 1.3, -0.7);
	glVertex3f(1.5, 0.3, -1.4);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0.3, -1.4);
	glVertex3f(0.7, 1.3, -0.7);
	glVertex3f(0, 0.3, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0.3, -1.4);
	glVertex3f(0.7, 1.3, -0.7);
	glVertex3f(1.5, 0.3, -1.4);
	glEnd();

	//2nd piramid
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5, 0.3, -1.5);
	glVertex3f(0, 0.3, -1.5);
	glVertex3f(0, 0.3, -2.9);
	glVertex3f(1.5, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0.3, -1.5);
	glVertex3f(0.7, 1.3, -2.2);
	glVertex3f(1.5, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5, 0.3, -2.9);
	glVertex3f(0.7, 1.3, -2.2);
	glVertex3f(1.5, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5, 0.3, -2.9);
	glVertex3f(0.7, 1.3, -2.2);
	glVertex3f(0, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0, 0.3, -1.5);
	glVertex3f(0.7, 1.3, -2.2);
	glVertex3f(0, 0.3, -2.9);
	glEnd();

	//3rd piramid
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.5, 0.3, -3);
	glVertex3f(0, 0.3, -3);
	glVertex3f(0, 0.3, -4.4);
	glVertex3f(1.5, 0.3, -4.4);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.5, 0.3, -3);
	glVertex3f(0.7, 1.3, -3.7);
	glVertex3f(0, 0.3, -3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5, 0.3, -3);
	glVertex3f(0.7, 1.3, -3.7);
	glVertex3f(1.5, 0.3, -4.4);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0, 0.3, -4.4);
	glVertex3f(0.7, 1.3, -3.7);
	glVertex3f(0, 0.3, -3);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.5, 0.3, -3);
	glVertex3f(0.7, 1.3, -3.7);
	glVertex3f(0, 0.3, -4.4);
	glEnd();

	//glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidSphere(5, 1, 1);
	
	
	//4th king
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0.3, -5.2);
	glVertex3f(0.7, 0.3, -5.2);
	glVertex3f(0, 1.3, -5.2);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5, 0.3, -5.2);
	glVertex3f(0.7, 0.3, -5.2);
	glVertex3f(1.5, 1.3, -5.2);
	glEnd();

	//5th king
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0.3, -6.75);
	glVertex3f(0.7, 0.3, -6.75);
	glVertex3f(0, 1.3, -6.75);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.5, 0.3, -6.75);
	glVertex3f(0.7, 0.3, -6.75);
	glVertex3f(1.5, 1.3, -6.75);
	glEnd();




}


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200);
	gluLookAt(0.0f, 12.5f, 15.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
}

void drawRightPieces() {


	//first cube
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.5, 0.3, 0);
	glVertex3f(10.5, 1.5, 0);
	glVertex3f(12, 1.5, 0);
	glVertex3f(12, 0.3, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(10.5, 0.3, -1.4);
	glVertex3f(10.5, 1.5, -1.4);
	glVertex3f(12, 1.5, -1.4);
	glVertex3f(12, 0.3, -1.4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.5, 0.3, 0);
	glVertex3f(10.5, 0.3, -1.4);
	glVertex3f(12, 0.3, -1.4);
	glVertex3f(12, 0.3, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(10.5, 1.5, 0);
	glVertex3f(10.5, 1.5, -1.4);
	glVertex3f(12, 1.5, -1.4);
	glVertex3f(12, 1.5, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(12, 0.3, -1.4);
	glVertex3f(12, 0.3, 0);
	glVertex3f(12, 1.5, 0);
	glVertex3f(12, 1.5, -1.4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.5, 0.3, 0);
	glVertex3f(10.5, 1.5, 0);
	glVertex3f(10.5, 1.5, -1.4);
	glVertex3f(10.5, 0.3, -1.4);
	glEnd();



	//piramid

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(12, 0.3, -1.5);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(10.5, 0.3, -2.9);
	glVertex3f(12, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(12, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(12, 0.3, -2.9);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(12, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(12, 0.3, -2.9);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(10.5, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(10.5, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(22.5, 10.3, -1.5);
	glVertex3f(31.2, 11.3, -2.2);
	glVertex3f(32, 10.3, -1.5);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(12, 0.3, -1.5);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(10.5, 0.3, -2.9);
	glVertex3f(12, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(12, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(12, 0.3, -2.9);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(12, 0.3, -1.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12, 0.3, -2.9);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(10.5, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(10.5, 0.3, -1.5);
	glVertex3f(11.2, 1.3, -2.2);
	glVertex3f(10.5, 0.3, -2.9);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(22.5, 10.3, -1.5);
	glVertex3f(31.2, 11.3, -2.2);
	glVertex3f(32, 10.3, -1.5);
	glEnd();
}


void drawBlackArea()
{
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	//glTranslatef(0.0f,0.0f,0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.3f, 0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);


	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(1.5f, 0.3f, 0.0f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(1.50f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.50f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(0.0f, 0.0f, -1.5f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(1.50f, 0.3f, 0.0f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);
	glEnd();
	//    glPopMatrix();

}
void drawWhiteArea()
{
	// glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	//glTranslatef(0.0f,0.0f,0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.3f, 0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(1.5f, 0.3f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(1.50f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.50f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(1.50f, 0.3f, 0.0f);
	glVertex3f(1.5f, 0.3f, -1.5f);
	glVertex3f(0.0f, 0.3f, -1.5f);
	glEnd();
	// glPopMatrix();

}

void myInit()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
	//list for board
	list_blackArea = glGenLists(1);
	glNewList(list_blackArea, GL_COMPILE);
	drawBlackArea();
	glEndList();
	list_whiteArea = glGenLists(2);
	glNewList(list_whiteArea, GL_COMPILE);
	drawWhiteArea();
	glEndList();
	//list for left right pieces
	drawLeftPieces();
	drawRightPieces();
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	drawLeftPieces();
	drawRightPieces();
	glLoadIdentity();
	glRotatef(_angle, _angle, 1.0f, _angle);
	glTranslatef(-4 * 1.5, 0.0, 4 * 1.5);

	for (float j = 0.0; j>(-8 * 1.5); j -= 1.5)
	{
		k++;
		for (i = 0.0; i<(4 * 3.0); i += 3.0)
		{
			if (k % 2 == 0)
			{
				glPushMatrix();
				glTranslatef(i, 0.0, j);
				glCallList(list_blackArea);
				glPopMatrix();

			}
			else
			{
				glPushMatrix();
				glTranslatef(i + 1.5, 0.0, j);
				glCallList(list_blackArea);
				glPopMatrix();

			}
		}
	}
	for (float j = 0.0; j>(-8 * 1.5); j -= 1.5)
	{
		k++;
		for (i = 0.0; i<(4 * 3.0); i += 3.0)
		{
			if (k % 2 != 0)
			{
				glPushMatrix();
				glTranslatef(i, 0.0, j);
				glCallList(list_whiteArea);
				glPopMatrix();

			}
			else
			{
				glPushMatrix();
				glTranslatef(i + 1.5, 0.0, j);
				glCallList(list_whiteArea);
				glPopMatrix();

			}
		}
	}
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("");
	glutInitWindowSize(600, 600);
	myInit();
	glutDisplayFunc(myDisplay);
	//glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;
}
