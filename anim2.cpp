/*
*Venegas Guerrero Fatima Alejandra 
* Animacion planeta
*
*el efecto de la camara lo vi en un ejemplo que me gusto
*/

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

//rotara -90 grados por el eje  de las  x que lleva de  (0,0,1) al (0,1,0).
void myWireSphere(GLfloat radius, int slices, int stacks) {
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glutWireSphere(radius, slices, stacks);
  glPopMatrix();
}

// actual "año-year" "day-dia" variables globales
//hacemos que el planeta gire alredador incrmentando 5 grados a año y rotamos 
//el planeta en su propio eje e decrementamos -10 el dia

static int year = 0, day = 0;


void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  //dibujamos el sol amarillo de una esfera de radio 1 centrado en el origen
  glColor3f(1.0, 1.0, 0.0);
  myWireSphere(1.0, 15, 15);
  //Dibujamos el planeta de colo azul de radio 0.2  y dos unidades lejos del sol
  glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
  glTranslatef (2.0, 0.0, 0.0);
  glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  myWireSphere(0.2, 15, 15);
  glColor3f(1, 1, 1);
  glBegin(GL_LINES);
    glVertex3f(0, -0.3, 0);
    glVertex3f(0, 0.3, 0);
  glEnd();

  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

//AQUI viene lo de la camara,
//esta camara esta como un comenta orbitando el sol con un año 8 veces
//mas que el planeta 
//La animacion se ejecuta con la funcion nextAnimationFrame() esta incrementa
//el valor de u ("mueve la camra") y elige otra posicion para orientar la camara 
static GLfloat u = 0.0;                 // para mover la camara
static GLfloat du = 0.1;                // se incremeta el frame

void timer(int v) {
  u += du;
  day = (day + 1) % 360;
  year = (year + 2) % 360;
  glLoadIdentity();
  gluLookAt(20*cos(u/8.0)+12,5*sin(u/8.0)+1,10*cos(u/8.0)+2, 0,0,0, 0,1,0);
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, v);
}


void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Planeta_Animacion2");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}