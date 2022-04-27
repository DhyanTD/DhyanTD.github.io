#include<stdio.h>
#include<math.h>
#include<glut.h>


GLint X1,X2,Y1,Y2;
void LineBres(void)
{
glClear(GL_COLOR_BUFFER_BIT);
int dx=abs(X2-X1), dy=abs(Y2-Y1);
int p=2*dy-dx;
int twoDy=2*dy, twoDyDx=2*(dy-dx);
int X,Y;
if(X1>X2)
{
    X=X2;
	Y=Y2;
	X2=X1;
}
else
{
	X=X1;
	Y=Y2;
	X2=X2;
}
glBegin(GL_POINTS);
glVertex2i(X,Y);
while(X<X2)
{
	X++;
	if(p<0)
		p+=twoDy;
	else
	{
	Y++;
	p+=twoDyDx;
	}
	glVertex2i(X,Y);

}
glEnd();
glFlush();

}
void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
}
void main(int argc, char **argv)
{
	printf("enter two points for darwn line bresenham:\n");
	printf("\n enter the point1(X1,Y1)");
	scanf_s("%d%d",&X1,&Y1);
	printf("\n enter the point2(X2,Y2)");
	scanf_s("%d%d",&X2,&Y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,400);
	glutCreateWindow("LineBresenham");
	Init();
	glutDisplayFunc(LineBres);
	glutMainLoop();

}
