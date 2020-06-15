/*
*Venegas Guerrero Fatima Alejandra 
* Animacion esfera
*
*/

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>



void display() {
   float  velRotacion += 2.0f; //Velocidad a la que rota la esfera
        
        //Clear the drawing area
        glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        //creamos la ESFERA
        glTranslatef(0.0f, 0.0f, -1.0f); //Permite enfocar la esfera
        glRotatef(velRotacion, 0.0f, 0.0f, -2.0f); //Permite la rotacion de la esfera
        glColor3f( 0.6f , 0.5f , 0.7f );
        //gluLookAt(1, 1, 5, 0, 0, 0, 1, 1, 0);
        glutWireSphere(2d, 40, 50);   
        glFlush();
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
  glutCreateWindow("Esfera_Animacion1");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
}