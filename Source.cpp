#include "glut.h"
#include "Funcion.h"

//Objeto de la clase función
Funcion func;

//Varaibles locales
int ancho = 500, alto = 500;
float GX = ancho / 2, GY = alto / 2;
float yi = 15, xi = 10, yf = 26, xf = 24, Xini, Yini,r;

//Llamamos al plano antes que todo
void plano() {
	func.plano();
}

//Aquí declaramos el menu con el click
void menu(int value) {
	switch (value)
	{
	case 1:
		func.circulo();
		break;
	case 2:
		func.elipse();
		break;
	case 3:
		func.limpiar();
		func.plano();
		break;
	case 4:
		exit(0);
		break;
	}
	
}

//Todo lo que tiene que contener el main para iniciar glut
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);//inicializamos glutInit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA/*R=rojo,G=verde,B=Azul,A=Opacidad*/);//buffers
	glutInitWindowSize(ancho, alto);// tamaño de la ventana
	glutInitWindowPosition(100, 100);//posicion de la ventana
	glutCreateWindow("Relleno de Figuras");//creacion y titulo de la ventana
	gluOrtho2D(-GX, GX, -GY, GY);//punto exacto en la ventana
	int sub1 = glutCreateMenu(menu); //inicio creacion de menu
	glutAddMenuEntry("Circulo", 1);
	glutAddMenuEntry("Elipse", 2);
	glutAddMenuEntry("Limpiar",3);
	glutCreateMenu(menu);
	glutAddSubMenu("Dibujar", 1);
	glutAddMenuEntry("Salir", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glClearColor(0, 0, 0, 0);//color base de la ventana RGBA
	glutDisplayFunc(plano);
	glutMainLoop();//loop para salir
	return 0;
}