
/*
*
*Venegas Guerrero Fatima Alejandra
*Graficacion por Computadora
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>

//Definimos algunas constantes
#define PI 3.141592653589;
#define Frac_Circ 100;

//Inicializamos las funciones
void triangulo_1(void);
void cuadrado_2(void);
void cuadrado_3(void);
void circulo(void);
void circulo_2(void);

//Funcion del Teclado
void myKeyboard(unsigned char key, int x, int y)
{
	switch(key){

		case '1':
		glutDisplayFunc(triangulo_1);
		break;
		
		case '3':
		   exit(0);
		break;
	}

}

//Cuadrado con GL_POLYGON
void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT); 
glColor3d(1.0, 0.0, 0.0); // red
glBegin(GL_POLYGON);
glVertex2d(-0.5, -0.5);
glVertex2d( 0.5, -0.5);
glVertex2d( 0.5, 0.5);
glVertex2d(-0.5, 0.5);
glEnd();
glFlush();
}

//Triangulo con GL_TRIANGLES
void triangulo_1(){
glClear(GL_COLOR_BUFFER_BIT); 
glColor3d(1.0, 0.0, 0.0); // red

glBegin(GL_TRIANGLES);
glVertex2d(-0.2, -0.1);
glVertex2d(0.1, -0.1);
glVertex2d(0.0, 0.2);
glEnd();

glFlush();

}

//Cuadrado dibujado con GL_LINE_LOOP
void cuadrado_2(){

glClear(GL_COLOR_BUFFER_BIT); 
    glColor3d(0.0,0.0,1.0); //azul color
	 
	glBegin(GL_LINE_LOOP);
      glVertex3d(-1.0,0.0,0.0);//izquiera de la ventanda
      glVertex3d(0.0,-1.0,0.0);//abajo  de la ventana
      glVertex3d(1.0,0.0,0.0);//derecho  de la ventana
      glVertex3d(0.0,1.0,0.0);//arriba de la ventana
    glEnd();
    glFlush();
}

//Cuadrado dibujado con GL_POLYGON
void cuadrado_3(){

glClear(GL_COLOR_BUFFER_BIT); 
   glColor3d(0.0,0.0,1.0); //azul color
  
    glBegin(GL_POLYGON);
      glVertex3d(-0.5,0.5,0.0);//primer vertice
      glVertex3d(0.5,0.5,0.0);//segundo vertice
      glVertex3d(0.5,-0.5,0.0);//tercer vertice
      glVertex3d(-0.5,-0.5,0.0);//cuarto vertice
    glEnd();
    glFlush();

}

//Circulo con GL_LINE_LOOP
void circulo(){

	float cx=0;
	float cy=0;
	float r=0.7;
	int num_segments=100;

glClear(GL_COLOR_BUFFER_BIT); 
     glColor3d(0.0,0.0,1.0); //azul
	 glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);
        float y = r * sinf(theta); 
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
    glFlush();

}

//Ciculo con GL_TRIANGLE_FAN
void circulo_2(){

	glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0,0.0,1.0); //azul

    int i, x, y;
    double radius = 0.30;
    double twicePi = 2.0 * 3.142; x = 0, y = 0;

    glBegin(GL_TRIANGLE_FAN); 
    glVertex2f(x, y); //centro del circulo
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
	

   glEnd();  
   glFlush();


}


void myInit(char *progname)
{
glutInitDisplayMode(GLUT_RGBA); 
glutInitWindowSize(500, 400);
glutInitWindowPosition(0, 0); 
glutCreateWindow(progname);
glClearColor(0.0, 0.0, 0.0, 1.0); 
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
myInit("Tarea01");
glutKeyboardFunc(myKeyboard);
//Circulo con GL_LINE_LOOP
//glutDisplayFunc(circulo);
//Ciculo con GL_TRIANGLE_FAN
//glutDisplayFunc(circulo_2);

//primer cuadrado GL_POLYGON
glutDisplayFunc(myDisplay);
//Cuadrado dibujado con GL_LINE_LOOP
//glutDisplayFunc(cuadrado_2);
//Cuadrado dibujado con GL_POLYGON
//glutDisplayFunc(cuadrado_3);
glutMainLoop();
return 0;
}