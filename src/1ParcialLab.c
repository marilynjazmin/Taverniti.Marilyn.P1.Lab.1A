#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nexo.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "input.h"
#include "menu.h"
#include "servicio.h"
#define TAM_A 1000
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4

int main(void) {
	setbuf(stdout,NULL);

	char opcion;
	int id=1;
	int flagAlta=0;
	eAuto listaAutos[TAM_A];

	eMarca listaMarcas[TAM_M]={{1000,"Renault"},
						   {1001,"Ford"},
						   {1002,"Fiat"},
						   {1003,"Chevrolet"},
						   {1004,"Peugeot"}};

	eColor listaColores[TAM_C]={{5000,"Negro"},
							{5001,"Blanco"},
							{5002,"Rojo"},
							{5003,"Gris"},
							{5004,"Azul"}};

	eServicio listaServicios[4]={{20000,"Lavado",450},
							     {20001,"Pulido",500},
								 {20002,"Encerado",600},
								 {20003,"Completo",900}};

	inicializarListaAutos(listaAutos, TAM_A);
	hardcodeoAutos(listaAutos, TAM_A, 4, &id);

	do
	{
		opcion=menuPrincipal();
		switch(opcion)
		{
		case 'a':
			altaAuto(&id, listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
			flagAlta=1;
			break;
		case 'b':
			if(flagAlta==1)
			{
				modificarAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
			}
			else
			{
				printf("\nPrimero debe ingresar al menos un auto.\n");
			}
			break;
		case 'c':
			if(flagAlta==1)
			{
				bajaAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
			}
			else
			{
				printf("\nPrimero debe ingresar al menos un auto.\n");
			}
			break;
		case 'd':
			if(flagAlta==1)
			{
				listarAutosPorMarca(listaAutos, TAM_A);
				mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
			}
			else
			{
				printf("\nPrimero debe ingresar al menos un auto.\n");
			}
			break;
		case 'e':
			mostrarMarcas(listaMarcas, TAM_M);
			break;
		case 'f':
			mostrarColores(listaColores, TAM_C);
			break;
		case 'g':
			mostrarServicios(listaServicios, TAM_S);
			break;
		case 'h':
			break;
		case 'i':
			break;
		case 'j':
			printf("\nFin.\n");
			break;
		default:
			printf("\nIngrese una opción válida.\n");
			break;
		}
	}while(opcion!='j');

	return EXIT_SUCCESS;
}
