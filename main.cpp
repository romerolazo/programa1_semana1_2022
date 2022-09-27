#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

//funcion para trabajar con mas valores en pantalla y no restringido a -1 a 1
void pantalla()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10,10,-10,10);

}

void cuadrado(float x, float y, float z, float a, float b, float c, float d, float e, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glVertex2f(d,e);

    glEnd();
}

void cuadrado_borde (float x, float y, float z, float a, float b, float c, float d, float e, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glVertex2f(d,e);

    glEnd();
}

void triangulo_borde (float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}


void triangulo (float x, float y, float z, float a, float b, float c, float *color, float s)
{
    glColor3fv(color);
    glLineWidth(s);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(x,y);
    glVertex2f(z,a);
    glVertex2f(b,c);
    glEnd();


}


void display(void)
{
glClearColor(1,1,1,1);//color de la ventana negro
glClear(GL_COLOR_BUFFER_BIT);
//glPointSize(7); // incrementa el tamaño del punto
//glLineWidth(5);//incrementa el ancho de la linea



cuadrado(-1,0,1,2,-1,4,-3,2,verde,3);
cuadrado(1,2,1,6,-1,8,-1,4,rosa,3);

triangulo(-1,5,-1,8,-4,5,naranja,3);
triangulo(-1,0,-3,2,-3,-2,cyan,3);
triangulo(-3,-2,0,-5,0,1,rojo,3);
triangulo(0,-5,0,1,6,-5,azul,3);
triangulo(4,-3,8,1,0,1,cyan,3);

cuadrado_borde(-1,0,1,2,-1,4,-3,2,negro,3);
cuadrado_borde(1,2,1,6,-1,8,-1,4,negro,3);

triangulo_borde(-1,5,-1,8,-4,5,negro,3);
triangulo_borde(-1,0,-3,2,-3,-2,negro,3);
triangulo_borde(-3,-2,0,-5,0,1,negro,3);
triangulo_borde(0,-5,0,1,6,-5,negro,3);
triangulo_borde(4,-3,8,1,0,1,negro,3);

 glutSwapBuffers();// opcional funciona para algunos con esta funcion,... glFlush()
}

//funcion principal, siempre es de esa manera
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);//Sirve para inicializar mi ventana de opengl
    glutInitWindowPosition(0,0);//parte la ventana en 4 partes y en (0,0) esta en el centro,posicion de mi ventana
    glutInitWindowSize(600,600);//tamaño de mi ventana tamaño normal (600,600)
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);//tipo de modo de visualizacion de la ventana

    glutCreateWindow("Primer programa");//Colocar el nombre que se le da a la ventana
    glutDisplayFunc(display);//nombre de la función
    pantalla();
    //glClearColor(1,1,1,1);//color de la ventana negro
    glutMainLoop();//hace que aparezca la ventana
    return EXIT_SUCCESS; //tambien se puede usar el return
}











