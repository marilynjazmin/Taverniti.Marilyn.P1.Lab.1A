#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef INPUT_H_
#define INPUT_H_

void pedirCadena(char* cadena, char mensaje[], char mensajeError[]);
void pedirCaracter(char* letra, char mensaje[], char mensajeError[]);
int validacionCadena(char cadena[]);
int pedirFlotante(float* numero, char* mensaje, char* mensajeError, int min, int max);
int validarNumero (char numeros[]);
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
void getString(char cadena[], char mensaje[]);
int pedirNumero(char mensaje[]);

#endif /* INPUT_H_ */
