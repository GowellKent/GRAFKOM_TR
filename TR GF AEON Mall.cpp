#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#endif
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xtrans = 0.0f;
float ytrans = 0.0f;
float ztrans = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Hizkia Christanto - 672019016");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.662, 0.937, 0.933,0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
}

void bangunankanan(){
    glBegin(GL_LINE_LOOP);
        //depan dari kanan
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(150.0, -100.0, 20.0);
    glVertex3f(150.0, 150.0, 20.0);
    glVertex3f(150.0, 150.0, -70.0);
    glVertex3f(150.0, -100.0, -70.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -100.0, -70.0);
    glVertex3f(150.0, 150.0, -70.0);
    glVertex3f(150.0, 150.0,  -160.0);
    glVertex3f(150.0, -100.0, -160.0);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(150.0, -100.0, -160.0);
    glVertex3f(150.0, 150.0, -160.0);
    glVertex3f(150.0, 150.0, -205.0);
    glVertex3f(150.0, -100.0, -205.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -100.0, -205.0);
    glVertex3f(150.0, 150.0, -205.0);
    glVertex3f(150.0, 150.0,  -320.0);
    glVertex3f(150.0, -100.0, -320.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(150.0, -100.0, 40.0);
    glVertex3f(150.0, 150.0, 40.0);
    glVertex3f(150.0, 150.0, 20.0);
    glVertex3f(150.0, -100.0, 20.0);
    glEnd();

    //tembok tulisan aeon
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(50.0, -100.0, 40.0);
    glVertex3f(50.0, 150.0, 40.0);
    glVertex3f(150.0, 150.0, 40.0);
    glVertex3f(150.0, -100.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(70.0, -10.0, 40.1);
    glVertex3f(70.0, 180.0, 40.1);
    glVertex3f(150.0, 180.0, 40.1);
    glVertex3f(150.0, -10.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.827, 0.333, 0.505);
    glVertex3f(150.1, -10.0, 30);
    glVertex3f(150.1, 180.0, 30);
    glVertex3f(150.1, 180.0, 40.1);
    glVertex3f(150.1, -10.0, 40.1);
    glEnd();

    //bagian 1
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-150.0, 90.0, 40.0);
    glVertex3f(-150.0, 140.0, 40.0);
    glVertex3f(50.0, 140.0, 40.0);
    glVertex3f(50.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-220.0, 120.0, 40.0);
    glVertex3f(-220.0, 140.0, 40.0);
    glVertex3f(-150.0, 140.0, 40.0);
    glVertex3f(-150.0, 120.0, 40.0);
    glEnd();
 	glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-220.0, -50.0, 40.0);
    glVertex3f(-220.0, -40.0, 40.0);
    glVertex3f(-150.0, -40.0, 40.0);
    glVertex3f(-150.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(-270.0, 140.0, 40.0);
    glVertex3f(-220.0, 140.0, 40.0);
    glVertex3f(-220.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(50.0, 90.0, 40.0);
    glVertex3f(50.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-60.0, -100.0, 40.0);
    glVertex3f(-60.0, 50.0, 40.0);
    glVertex3f(50.0, 50.0, 40.0);
    glVertex3f(50.0, -100.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-130.0, -100.0, 40.0);
    glVertex3f(-130.0, 50.0, 40.0);
    glVertex3f(-60.0, 50.0, 40.0);
    glVertex3f(-60.0, -100.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, 30.0, 40.0);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-130.0, 50.0, 40.0);
    glVertex3f(-130.0, 30.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-150.0, 0.0, 40.0);
    glVertex3f(-150.0, 30.0, 40.0);
    glVertex3f(-130.0, 30.0, 40.0);
    glVertex3f(-130.0, 0.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, 0.0, 40.0);
    glVertex3f(-270.0, 30.0, 40.0);
    glVertex3f(-220.0, 30.0, 40.0);
    glVertex3f(-220.0, 0.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-270.0, 0.0, 40.0);
    glVertex3f(-130.0, 0.0, 40.0);
    glVertex3f(-130.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-150.0, -50.0, 40.0);
    glVertex3f(-150.0, -20.0, 40.0);
    glVertex3f(-130.0, -20.0, 40.0);
    glVertex3f(-130.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-270.0, -50.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-220.0, -20.0, 40.0);
    glVertex3f(-220.0, -50.0, 40.0);
    glEnd();

    //bagian 2
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 120.0, 40.0);
    glVertex3f(-430.0, 135.0, 40.0);
    glVertex3f(-270.0, 135.0, 40.0);
    glVertex3f(-270.0, 120.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-350.0, 120.0, 40.0);
    glVertex3f(-345.0, 120.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glVertex3f(-345.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-345.0, 80.0, 40.0);
    glVertex3f(-345.0, 90.0, 40.0);
    glVertex3f(-270.0, 90.0, 40.0);
    glVertex3f(-270.0, 80.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-270.0, 50.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-350.0, -50.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-345.0, -20.0, 40.0);
    glVertex3f(-345.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-345.0, -50.0, 40.0);
    glVertex3f(-345.0, -40.0, 40.0);
    glVertex3f(-270.0, -40.0, 40.0);
    glVertex3f(-270.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-275.0, -50.0, 40.0);
    glVertex3f(-275.0, -20.0, 40.0);
    glVertex3f(-270.0, -20.0, 40.0);
    glVertex3f(-270.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-430.0, 120.0, 40.0);
    glVertex3f(-425.0, 120.0, 40.0);
    glVertex3f(-425.0, 90.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, 80.0, 40.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-350.0, 90.0, 40.0);
    glVertex3f(-350.0, 80.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, 50.0, 40.0);
    glVertex3f(-430.0, 80.0, 40.0);
    glVertex3f(-425.0, 80.0, 40.0);
    glVertex3f(-425.0, 50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -20.0, 40.0);
    glVertex3f(-430.0, 50.0, 40.0);
    glVertex3f(-350.0, 50.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -50.0, 40.0);
    glVertex3f(-430.0, -20.0, 40.0);
    glVertex3f(-425.0, -20.0, 40.0);
    glVertex3f(-425.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-355.0, -50.0, 40.0);
    glVertex3f(-355.0, -20.0, 40.0);
    glVertex3f(-350.0, -20.0, 40.0);
    glVertex3f(-350.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -50.0, 40.0);
    glVertex3f(-430.0, -40.0, 40.0);
    glVertex3f(-350.0, -40.0, 40.0);
    glVertex3f(-350.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.137, 0.082, 0.101);
    glVertex3f(-430.0, -50.0, -20.0);
    glVertex3f(-430.0, 90.0, -20.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glVertex3f(-430.0, -50.0, 40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-430.0, 90.0, -20.0);
    glVertex3f(-430.0, 135.0, -20.0);
    glVertex3f(-430.0, 135.0, 40.0);
    glVertex3f(-430.0, 90.0, 40.0);
    glEnd();

}

void gariskaca(){
     //garis garis kaca besar
    	glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, 120.0, 40.0);
		glVertex3f(-220.0, 120.0, 40.0);
		glVertex3f(-220.0, 90.0, 40.0);
		glVertex3f(-150.0, 90.0, 40.0);
		glEnd();
		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, 90.0, 40.0);
		glVertex3f(-210.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 90.0, 40.0);
		glVertex3f(-200.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, 90.0, 40.0);
		glVertex3f(-190.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 90.0, 40.0);
		glVertex3f(-180.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, 90.0, 40.0);
		glVertex3f(-170.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 90.0, 40.0);
		glVertex3f(-160.0, 120.0, 40.0);
		glEnd();

    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, 30.0, 40.0);
		glVertex3f(-220.0, 30.0, 40.0);
		glVertex3f(-220.0, 0.0, 40.0);
		glVertex3f(-150.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-150.0, -20.0, 40.0);
		glVertex3f(-220.0, -20.0, 40.0);
		glVertex3f(-220.0, -40.0, 40.0);
		glVertex3f(-150.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-270.0, 120.0, 40.0);
		glVertex3f(-345.0, 120.0, 40.0);
		glVertex3f(-345.0, 90.0, 40.0);
		glVertex3f(-270.0, 90.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-270.0, 80.0, 40.0);
		glVertex3f(-345.0, 80.0, 40.0);
		glVertex3f(-345.0, 50.0, 40.0);
		glVertex3f(-270.0, 50.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-275.0, -20.0, 40.0);
		glVertex3f(-345.0, -20.0, 40.0);
		glVertex3f(-345.0, -40.0, 40.0);
		glVertex3f(-275.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-355.0, -20.0, 40.0);
		glVertex3f(-425.0, -20.0, 40.0);
		glVertex3f(-425.0, -40.0, 40.0);
		glVertex3f(-355.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-350.0, 80.0, 40.0);
		glVertex3f(-425.0, 80.0, 40.0);
		glVertex3f(-425.0, 50.0, 40.0);
		glVertex3f(-350.0, 50.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-350.0, 120.0, 40.0);
		glVertex3f(-425.0, 120.0, 40.0);
		glVertex3f(-425.0, 90.0, 40.0);
		glVertex3f(-350.0, 90.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, 30.0, 40.0);
		glVertex3f(-210.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, 30.0, 40.0);
		glVertex3f(-200.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, 30.0, 40.0);
		glVertex3f(-190.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, 30.0, 40.0);
		glVertex3f(-180.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, 30.0, 40.0);
		glVertex3f(-170.0, 0.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, 30.0, 40.0);
		glVertex3f(-160.0, 0.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-210.0, -20.0, 40.0);
		glVertex3f(-210.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-200.0, -20.0, 40.0);
		glVertex3f(-200.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-190.0, -20.0, 40.0);
		glVertex3f(-190.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-180.0, -20.0, 40.0);
		glVertex3f(-180.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-170.0, -20.0, 40.0);
		glVertex3f(-170.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-160.0, -20.0, 40.0);
		glVertex3f(-160.0, -40.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, 90.0, 40.0);
		glVertex3f(-330.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, 90.0, 40.0);
		glVertex3f(-320.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, 90.0, 40.0);
		glVertex3f(-310.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 90.0, 40.0);
		glVertex3f(-300.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, 90.0, 40.0);
		glVertex3f(-290.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 90.0, 40.0);
		glVertex3f(-280.0, 120.0, 40.0);
		glEnd();

			glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, 50.0, 40.0);
		glVertex3f(-330.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, 50.0, 40.0);
		glVertex3f(-320.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, 50.0, 40.0);
		glVertex3f(-310.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, 50.0, 40.0);
		glVertex3f(-300.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, 50.0, 40.0);
		glVertex3f(-290.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, 50.0, 40.0);
		glVertex3f(-280.0, 80.0, 40.0);
		glEnd();

			glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-330.0, -20.0, 40.0);
		glVertex3f(-330.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-320.0, -20.0, 40.0);
		glVertex3f(-320.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-310.0, -20.0, 40.0);
		glVertex3f(-310.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-300.0, -20.0, 40.0);
		glVertex3f(-300.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-290.0, -20.0, 40.0);
		glVertex3f(-290.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-280.0, -20.0, 40.0);
		glVertex3f(-280.0, -40.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, 90.0, 40.0);
		glVertex3f(-410.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 90.0, 40.0);
		glVertex3f(-400.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, 90.0, 40.0);
		glVertex3f(-390.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 90.0, 40.0);
		glVertex3f(-380.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, 90.0, 40.0);
		glVertex3f(-370.0, 120.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 90.0, 40.0);
		glVertex3f(-360.0, 120.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, 50.0, 40.0);
		glVertex3f(-410.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, 50.0, 40.0);
		glVertex3f(-400.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, 50.0, 40.0);
		glVertex3f(-390.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, 50.0, 40.0);
		glVertex3f(-380.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, 50.0, 40.0);
		glVertex3f(-370.0, 80.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, 50.0, 40.0);
		glVertex3f(-360.0, 80.0, 40.0);
		glEnd();

		glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-410.0, -20.0, 40.0);
		glVertex3f(-410.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-400.0, -20.0, 40.0);
		glVertex3f(-400.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-390.0, -20.0, 40.0);
		glVertex3f(-390.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-380.0, -20.0, 40.0);
		glVertex3f(-380.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-370.0, -20.0, 40.0);
		glVertex3f(-370.0, -40.0, 40.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0,0,0);
		glVertex3f(-360.0, -20.0, 40.0);
		glVertex3f(-360.0, -40.0, 40.0);
		glEnd();
}

void jendelakotak3(){
    //kaca yang kotak 3
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-130.0, 100.0, 40.1);
    glVertex3f(-130.0, 120.0, 40.1);
    glVertex3f(-110.0, 120.0, 40.1);
    glVertex3f(-110.0, 100.0, 40.1);
    glEnd();
        glLineWidth(2);
    glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
    glVertex3f(-130.0, 100.0, 40.1);
    glVertex3f(-130.0, 120.0, 40.1);
    glVertex3f(-110.0, 120.0, 40.1);
    glVertex3f(-110.0, 100.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-100.0, 100.0, 40.1);
    glVertex3f(-100.0, 120.0, 40.1);
    glVertex3f(-80.0, 120.0, 40.1);
    glVertex3f(-80.0, 100.0, 40.1);
    glEnd();
    glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
	glVertex3f(-100.0, 100.0, 40.1);
    glVertex3f(-100.0, 120.0, 40.1);
    glVertex3f(-80.0, 120.0, 40.1);
    glVertex3f(-80.0, 100.0, 40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.886, 0.854, 0.866);
    glVertex3f(-70.0, 100.0, 40.1);
    glVertex3f(-70.0, 120.0, 40.1);
    glVertex3f(-50.0, 120.0, 40.1);
    glVertex3f(-50.0, 100.0, 40.1);
    glEnd();
    glLineWidth(2);
    	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0);
    glVertex3f(-70.0, 100.0, 40.1);
    glVertex3f(-70.0, 120.0, 40.1);
    glVertex3f(-50.0, 120.0, 40.1);
    glVertex3f(-50.0, 100.0, 40.1);
    glEnd();
}

void tampil(void)
{
    if(is_depth){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }else{
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f,0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xtrans,ytrans,ztrans);
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
	//bagian tengah
     glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-900.0, 120.0, -20.0);
    glVertex3f(-430.0, 120.0, -20.0);
    glVertex3f(-430.0, 135.0, -20.0);
    glVertex3f(-900.0, 135.0, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.964, 0.937, 0.945);
    glVertex3f(-900.0, 0.0, -20.0);
    glVertex3f(-430.0, 0.0, -20.0);
    glVertex3f(-430.0, 50.0, -20.0);
    glVertex3f(-900.0, 50.0, -20.0);
    glEnd();
    
    //kanan bawah jendela
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-530.0, 0.0, -20.0);
    glVertex3f(-430.0, 0.0, -20.0);
    glVertex3f(-430.0, 25.0, -20.0);
    glVertex3f(-530.0, 25.0, -20.0);
    glEnd();
    
    
    //jendela kiri tengah
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-900.0, 50.0, -20.0);
    glVertex3f(-850.0, 50.0, -20.0);
    glVertex3f(-850.0, 120.0, -20.0);
    glVertex3f(-900.0, 120.0, -20.0);
    glEnd();
    
    //garis jendela kiri tengah
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-890.0, 50.0, -20.0);
    glVertex3f(-890.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-880.0, 50.0, -20.0);
    glVertex3f(-880.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-870.0, 50.0, -20.0);
    glVertex3f(-870.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-860.0, 50.0, -20.0);
    glVertex3f(-860.0, 120.0, -20.0);
    glEnd();
    
    //Jendela kanan
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, -20.0);
    glVertex3f(-430.0, 50.0, -20.0);
    glVertex3f(-430.0, 90.0, -20.0);
    glVertex3f(-530.0, 90.0, -20.0);
    glEnd();
    
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, -20.0);
    glVertex3f(-430.0, 90.0, -20.0);
    glVertex3f(-430.0, 120.0, -20.0);
    glVertex3f(-530.0, 120.0, -20.0);
    glEnd();
    
    //garis jendela kanan tengah
   	glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-520.0, 50.0, -20.0);
    glVertex3f(-520.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-510.0, 50.0, -20.0);
    glVertex3f(-510.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-500.0, 50.0, -20.0);
    glVertex3f(-500.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-490.0, 50.0, -20.0);
    glVertex3f(-490.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-480.0, 50.0, -20.0);
    glVertex3f(-480.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-470.0, 50.0, -20.0);
    glVertex3f(-470.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-460.0, 50.0, -20.0);
    glVertex3f(-460.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-450.0, 50.0, -20.0);
    glVertex3f(-450.0, 120.0, -20.0);
    
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-440.0, 50.0, -20.0);
    glVertex3f(-440.0, 120.0, -20.0);
    
    glEnd();
    
    //jendela hitam tengah
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, -20.0);
    glVertex3f(-530.0, 50.0, -20.0);
    glVertex3f(-530.0, 90.0, -20.0);
    glVertex3f(-850.0, 90.0, -20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, -20.0);
    glVertex3f(-850.0, 50.0, 0.0);
    glVertex3f(-850.0, 90.0, 0.0);
    glVertex3f(-850.0, 90.0, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, -20.0);
    glVertex3f(-530.0, 50.0, 0.0);
    glVertex3f(-530.0, 90.0, 0.0);
    glVertex3f(-530.0, 90.0, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 0.0);
    glVertex3f(-530.0, 90.0, 0.0);
    glVertex3f(-530.0, 90.0,-20.0);
    glVertex3f(-850.0, 90.0,-20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 50.0, 0.0);
    glVertex3f(-530.0, 50.0, 0.0);
    glVertex3f(-530.0, 50.0, -20.0);
    glVertex3f(-850.0, 50.0, -20.0);
    glEnd();
    
    //garis-garis jendela hitam
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-840.0, 50.0, 0.0);
    glVertex3f(-840.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-830.0, 50.0, 0.0);
    glVertex3f(-830.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-820.0, 50.0, 0.0);
    glVertex3f(-820.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-810.0, 50.0, 0.0);
    glVertex3f(-810.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-800.0, 50.0, 0.0);
    glVertex3f(-800.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-790.0, 50.0, 0.0);
    glVertex3f(-790.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-780.0, 50.0, 0.0);
    glVertex3f(-780.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-770.0, 50.0, 0.0);
    glVertex3f(-770.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-760.0, 50.0, 0.0);
    glVertex3f(-760.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-750.0, 50.0, 0.0);
    glVertex3f(-750.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-740.0, 50.0, 0.0);
    glVertex3f(-740.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-730.0, 50.0, 0.0);
    glVertex3f(-730.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-720.0, 50.0, 0.0);
    glVertex3f(-720.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-710.0, 50.0, 0.0);
    glVertex3f(-710.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-700.0, 50.0, 0.0);
    glVertex3f(-700.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-690.0, 50.0, 0.0);
    glVertex3f(-690.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-680.0, 50.0, 0.0);
    glVertex3f(-680.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-670.0, 50.0, 0.0);
    glVertex3f(-670.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-660.0, 50.0, 0.0);
    glVertex3f(-660.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-650.0, 50.0, 0.0);
    glVertex3f(-650.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-640.0, 50.0, 0.0);
    glVertex3f(-640.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-630.0, 50.0, 0.0);
    glVertex3f(-630.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-620.0, 50.0, 0.0);
    glVertex3f(-620.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-610.0, 50.0, 0.0);
    glVertex3f(-610.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-600.0, 50.0, 0.0);
    glVertex3f(-600.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-590.0, 50.0, 0.0);
    glVertex3f(-590.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-580.0, 50.0, 0.0);
    glVertex3f(-580.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-570.0, 50.0, 0.0);
    glVertex3f(-570.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-560.0, 50.0, 0.0);
    glVertex3f(-560.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-550.0, 50.0, 0.0);
    glVertex3f(-550.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-540.0, 50.0, 0.0);
    glVertex3f(-540.0, 90.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 50.0, 0.0);
    glVertex3f(-530.0, 90.0, 0.0);
    glEnd();
    
    //pembatas tengah jendela
     glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, -20.0);
    glVertex3f(-530.0, 90.0, -20.0);
    glVertex3f(-530.0, 120.0, -20.0);
    glVertex3f(-850.0, 120.0, -20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, -20.0);
    glVertex3f(-850.0, 90.0, 0.0);
    glVertex3f(-850.0, 120.0, 0.0);
    glVertex3f(-850.0, 120.0, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, -20.0);
    glVertex3f(-530.0, 90.0, 0.0);
    glVertex3f(-530.0, 120.0, 0.0);
    glVertex3f(-530.0, 120.0, -20.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 120.0, 0.0);
    glVertex3f(-530.0, 120.0, 0.0);
    glVertex3f(-530.0, 120.0,-20.0);
    glVertex3f(-850.0, 120.0,-20.0);
    glEnd();
    
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-850.0, 90.0, 0.0);
    glVertex3f(-530.0, 90.0, 0.0);
    glVertex3f(-530.0, 90.0, -20.0);
    glVertex3f(-850.0, 90.0, -20.0);
    glEnd();
    
    //garis atas tengah (bagian atas) pembatas jendela
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-840.0, 90.0, 0.0);
    glVertex3f(-840.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-830.0, 90.0, 0.0);
    glVertex3f(-830.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-820.0, 90.0, 0.0);
    glVertex3f(-820.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-810.0, 90.0, 0.0);
    glVertex3f(-810.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-800.0, 90.0, 0.0);
    glVertex3f(-800.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-790.0, 90.0, 0.0);
    glVertex3f(-790.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-780.0, 90.0, 0.0);
    glVertex3f(-780.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-770.0, 90.0, 0.0);
    glVertex3f(-770.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-760.0, 90.0, 0.0);
    glVertex3f(-760.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-750.0, 90.0, 0.0);
    glVertex3f(-750.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-740.0, 90.0, 0.0);
    glVertex3f(-740.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-730.0, 90.0, 0.0);
    glVertex3f(-730.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-720.0, 90.0, 0.0);
    glVertex3f(-720.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-710.0, 90.0, 0.0);
    glVertex3f(-710.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-700.0, 90.0, 0.0);
    glVertex3f(-700.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-690.0, 90.0, 0.0);
    glVertex3f(-690.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-680.0, 90.0, 0.0);
    glVertex3f(-680.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-670.0, 90.0, 0.0);
    glVertex3f(-670.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-660.0, 90.0, 0.0);
    glVertex3f(-660.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-650.0, 90.0, 0.0);
    glVertex3f(-650.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-640.0, 90.0, 0.0);
    glVertex3f(-640.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-630.0, 90.0, 0.0);
    glVertex3f(-630.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-620.0, 90.0, 0.0);
    glVertex3f(-620.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-610.0, 90.0, 0.0);
    glVertex3f(-610.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-600.0, 90.0, 0.0);
    glVertex3f(-600.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-590.0, 90.0, 0.0);
    glVertex3f(-590.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-580.0, 90.0, 0.0);
    glVertex3f(-580.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-570.0, 90.0, 0.0);
    glVertex3f(-570.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-560.0, 90.0, 0.0);
    glVertex3f(-560.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-550.0, 90.0, 0.0);
    glVertex3f(-550.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-540.0, 90.0, 0.0);
    glVertex3f(-540.0, 120.0, 0.0);
    glEnd();
    
     glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glVertex3f(-530.0, 90.0, 0.0);
    glVertex3f(-530.0, 120.0, 0.0);
    glEnd();
    bangunankanan();
    gariskaca();
    jendelakotak3();
    
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'w':
		case 'W':
			ztrans += 3;
		break;
		case 'd':
		case 'D':
			xtrans += 3;
		break;
		case 's':
		case 'S':
			ztrans -= 3;
		break;
		case 'a':
		case 'A':
			xtrans -= 3;
		break;
		case 'l':
		case 'L':
			ytrans += 3;
		break;
		case 'h':
		case 'H':
			ytrans -= 3;
		break;
		case '5':
			if(is_depth){
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			} else {
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
			
	}
		tampil();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff= x - yrot;
        ydiff= -y +xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
