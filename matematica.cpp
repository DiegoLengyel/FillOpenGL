//Las libreria que necesitamos.
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "Funcion.h"


//Aquí pintamos todo lo que necesitamos
void Funcion::pintaFuncion(float CX, float CY, float Red, float Green, float Blue) {
	//glClear(GL_COLOR_BUFFER_BIT);//limpiar el buffer de color
	glPointSize(8);//tamaño del pixel
	glColor3f(Red, Green, Blue);//definir color
	glBegin(GL_POINTS);
	glVertex2d(CX, CY);//definir coordenadas
	glEnd();//termina el glBegin
	glutSwapBuffers();
}

//Aquí limpiamos la pantalla
void Funcion::limpiar() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glFlush();
	glutSwapBuffers();
}

//Aqui graficamos la elipse rellena
void Funcion::elipse() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.2, 0.2);//DEFINO COLOR
	//int r = 0; //radio 
	int x, y;   //Coordenadas para glvetex2d
	int theta1; //Ángulo en grados
	int theta2; //Ángulo en radianes
	//while (r < 20) {   //Para que llegue a un radio definido y no se pase
		while (c <= a || d <= b) {
			for (theta1 = 0; theta1 < 360; theta1++) {
				theta2 = (int)((theta1 * 180) / PI);
				x = (int)(c * cos(theta2)); //cálculo de x para glut
				y = (int)(d * sin(theta2)); //cálculo de y para glut
				pintaFuncion(x, y, 1, 0.4, 0.6);
			}
			c = c + 2;
			d = d++;
		}
		//r = r + 2; //iterador para que glut vaya dibujando vez por vez el radio
	//}
	glFlush();
}

//Aqui graficamos el circulo relleno
void Funcion::circulo()
{
	srand(time(NULL));
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.2, 0.2);//DEFINO COLOR
	int r = 0; //radio 
	int x, y;   //Coordenadas para glvetex2d
	int theta1; //Ángulo en grados
	int theta2; //Ángulo en radianes
	for (int i = 0; i <= 359; i++) {
		R[i] = (float)(rand() % 5);
		G[i] = (float)(rand() % 5);
		B[i] = (float)(rand() % 5);
	}
	while (r < 20) {   //Para que llegue a un radio definido y no se pase
		for (theta1 = 0; theta1 < 360; theta1++) {
			theta2 = (int)((theta1 * 180) / PI);
			x = (int)(r * cos(theta2)); //cálculo de x para glut
			y = (int)(r * sin(theta2)); //cálculo de y para glut
			pintaFuncion(x, y, R[theta1], G[theta1], B[theta1]);
		}
		r = r + 2; //iterador para que glut vaya dibujando vez por vez el radio
	}
	glFlush();
}

//Aqui graficamos el plano
void Funcion::plano() {
	for (float i = -GX; i < GX; i++)
	{
		pintaFuncion(i, 0, 1, 1, 1);//dibuja pixeles en el eje x
	}
	for (float i = -GY; i < GY; i++)
	{
		pintaFuncion(0, i, 1, 1, 1);//dibuja pixeles en el eje y
	}
}
