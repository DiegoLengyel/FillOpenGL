#pragma once
//Declaramos la clase para inicializar todo
class Funcion {
	//Aquí declaramos las variables
public:
	int ancho = 500, alto = 500;
	float GX = ancho / 2, GY = alto / 2;
	float r=0;
	float x = 0, y = 0 , a = 50, b = 25, c=0, d=0;
	float PI = 3.1416;
	float R[360], G[360], B[360];
	//Aquí declaramos las funciones
public:
	void pintaFuncion(float, float, float, float, float);
	void plano();
	void limpiar();
	void elipse();
	void circulo();
	~Funcion() {};
};