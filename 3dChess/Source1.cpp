#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define width  700
#define height 700

#define r  11
#define br 21
#define n  12
#define bn 22
#define b  13
#define bb 23
#define k  14
#define bk 24
#define q  15
#define bq 25
#define p  16
#define bp 26

using namespace std;

std::pair <int, int> board[8][8]{
	{ { br, 0 },{ bn, 1 },{ bb, 0 },{ bq, 1 },{ bk, 0 },{ bb, 1 },{ bn, 0 },{ br, 1 } },
{ { bp, 1 },{ bp, 0 },{ bp, 1 },{ bp, 0 },{ bp, 1 },{ bp, 0 },{ bp, 1 },{ bp, 0 } },
{ { 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 } },
{ { 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 } },
{ { 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 } },
{ { 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 },{ 0, 1 },{ 0, 0 } },
{ { p, 0 },{ p, 1 },{ p, 0 },{ p, 1 },{ p, 0 },{ p, 1 },{ p, 0 },{ p, 1 } },
{ { r, 1 },{ n, 0 },{ b, 1 },{ q, 0 },{ k, 1 },{ b, 0 },{ n, 1 },{ r, 0 } }
};


int swapx = -1, swapy = -1, swapx2 = -1, swapy2 = -1;
float _angle = 0;
float i;
int kk = 0;

float x11, y11, z11;

class figures {
public:
	void draw(int id) {
		if (id / 10 == 2)
			glColor3d(0, 0, 0);
		else
			glColor3d(1, 1, 1);

		switch (id)
		{
		case r:
		case br:
			rook();
			break;
		case n:
		case bn:
			knight();
			break;
		case b:
		case bb:
			bishop();
			break;
		case q:
		case bq:
			queen();
			break;
		case k:
		case bk:
			king();
			break;
		case p:
		case bp:
			pawn();
			break;
		default:;
		}
	}
private:
	void pawn()
	{
		glPushMatrix();
		glColor3f(1, 0.5, 0);
		glRotated(-90, 1, 0, 0);
		glutSolidCone(0.5, 1, 20, 20);
		glPopMatrix();
	}

	void king()
	{
		glPushMatrix();
		glColor3f(1, 0.5, 0.5);
		glTranslated(0, 0.5, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	void queen()
	{
		glPushMatrix();
		glColor3f(0, 0.5, 30.5);
		glTranslated(0, 0.5, 0);
		glutWireCube(1);
		glPopMatrix();
	}

	void rook()
	{
		glPushMatrix();
		glColor3f(1.5, 0.5, 2);
		glTranslated(0, 0.5, 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();
	}

	void bishop()
	{
		glPushMatrix();
		glColor3f(1, 0.5, 2.50);
		glRotated(-90, 1, 0, 0);
		glutWireCone(0.5, 2, 20, 20);
		glPopMatrix();
	}

	void knight()
	{
		glPushMatrix();
		glTranslated(0, 0.1, 0);
		glColor3f(10, 0.1, 2.50);
		glRotated(90, 1, 0, 0);
		glutSolidTorus(0.1, 0.5, 20, 20);
		glPopMatrix();
	}
};

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200);
	gluLookAt(-20.0f, 10.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
}

void drawRect(int i, int j) {
	float dx = 1.5, dy = 0.3, dz = 1.5;

	glBegin(GL_QUADS);
	switch (board[j][i].second)
	{
	case 0:
		glColor3f(0.6, 0.6, 0.6);
		break;
	case 1:
		glColor3f(0.3, 0.3, 0.3);
		break;
	case 2:
	case 3:
		glColor3f(0.5, 1, 0.5);
		break;
	case 4:
	case 5:
		if (board[j][i].first > 0)
			glColor3f(1, 0.7, 0.7);
		else
			glColor3f(0.7, 1, 0.7);
		break;
	}
	glVertex3f(0, dy, 0);
	glVertex3f(dx, dy, 0);
	glVertex3f(dx, dy, dz);
	glVertex3f(0, dy, dz);
	glEnd();

	glColor3f(0.05f, 0.05f, 0.15f);

	glBegin(GL_QUADS);
	glTranslatef(0, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(dx, 0, 0);
	glVertex3f(dx, dy, 0);
	glVertex3f(0, dy, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, dz);
	glVertex3f(0, dy, dz);
	glVertex3f(0, dy, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(dx, 0, 0);
	glVertex3f(dx, dy, dz);
	glVertex3f(dx, dy, dz);
	glVertex3f(dx, dy, 0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 0, dz);
	glVertex3f(dx, 0, dz);
	glVertex3f(dx, dy, dz);
	glVertex3f(0, dy, dz);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(dx, 0, 0);
	glVertex3f(dx, 0, dz);
	glVertex3f(0, 0, dz);
	glEnd();
}

void clrBoard(void)
{
	for (int i = 0; i<8; i++)
		for (int j = 0; j<8; j++)
			board[i][j].second %= 2;
	swapx = -1, swapy = -1, swapx2 = -1, swapy2 = -1;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
}

void drawScene() {
	float dx = 1.5, dz = 1.5;
	figures fig;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-4 * dx, 0, -4 * dz);



	for (int i = 0; i<8; i++) {
		for (int j = 0; j<8; j++) {
			glPushMatrix();
			glTranslatef(i*dx, 0, j*dz);
			glLineWidth(1);
			drawRect(i, j);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(i*dx + dx / 2, 0.3, j*dz + dz / 2);
			fig.draw(board[j][i].first);
			glPopMatrix();
		}
	}

	glutSwapBuffers();

}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27:
		exit(0);
		break;
	default:
		if (swapx == -1 || swapy == -1) {
			if (key >= 'a' && key <= 'h')
				swapx = (int)(key - 'a'), cout << "+\n";
			else if (key >= '1' && key <= '8' && swapx>-1)
				swapy = (int)(key - '1');

			if (swapy > -1 && board[swapy][swapx].first > 0)
				board[swapy][swapx].second = 2 + (board[swapy][swapx].second % 2),
				glutPostRedisplay();
			else if (swapy>-1 && board[swapy][swapx].first == 0)
				clrBoard();
		}
		else {
			if (key >= 'a' && key <= 'h')
				swapx2 = (int)(key - 'a'), cout << "-";
			else if (key >= '1' && key <= '8' && swapx2>-1)
				swapy2 = (int)(key - '1');


			if (swapy2 > -1 && board[swapy2][swapx2].first == 0)
				swap(board[swapy][swapx].first, board[swapy2][swapx2].first),
				clrBoard(),
				glutPostRedisplay();
			else if (swapy2>-1 && board[swapy2][swapx2].first > 0)
				clrBoard();
		}
	}
}

void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

void timer(int) {


	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("basic shape");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutTimerFunc(1, timer, 0);
	glutMainLoop();

	return 0;
}