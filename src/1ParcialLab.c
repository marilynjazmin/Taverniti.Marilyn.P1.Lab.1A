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
#include "trabajo.h"
#include "cliente.h"
#define TAM_A 1000
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10
#define TAM_CLIENTE 5

int main(void) {
	setbuf(stdout,NULL);

	char opcion;
	int retorno;
	int idAuto=666000;
	int idTrabajo=100000;
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

	eCliente listaClientes[TAM_CLIENTE]={{3030,"Tomás",'m'},
										{2130,"Lucas",'m'},
										{3040,"Lucía",'f'},
										{2279,"Mariana",'f'},
										{5066,"Nicolás",'m'},};

	eServicio listaServicios[TAM_S]={{20000,"Lavado",450},
							     {20001,"Pulido",500},
								 {20002,"Encerado",600},
								 {20003,"Completo",900}};

	eTrabajo listaTrabajos[TAM_T];

	inicializarListaAutos(listaAutos, TAM_A);
	inicializarListaTrabajos(listaTrabajos, TAM_T);
	retorno=hardcodeoAutos(listaAutos, TAM_A, 8, &idAuto);
	hardcodeoTrabajos(listaTrabajos, TAM_T, 1, &idTrabajo);

	do
	{
		opcion=menuPrincipal();
		switch(opcion)
		{
		case 'a':
			retorno=altaAuto(&idAuto, listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
			break;
		case 'b':
			if(retorno==1)
			{
				modificarAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'c':
			if(retorno==1)
			{
				bajaAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'd':
			if(retorno==1)
			{
				listarAutosPorMarca(listaAutos, TAM_A);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CLIENTE);
			break;
		case 'e':
			if(retorno==1)
			{
				mostrarMarcas(listaMarcas, TAM_M);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'f':
			mostrarColores(listaColores, TAM_C);
			break;
		case 'g':
			mostrarServicios(listaServicios, TAM_S);
			break;
		case 'h':
			if(retorno==1)
			{
				altaTrabajo(&idTrabajo, listaTrabajos, TAM_T, listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaServicios, TAM_S, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'i':
			if(retorno==1)
			{
				mostrarTrabajos(listaTrabajos, TAM_T, listaAutos, TAM_A, listaServicios, TAM_S);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'j':
			if(retorno==1)
			{
				mostrarAutosColor(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'k':
			if(retorno==1)
			{
				mostrarAutosMarca(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'l':
			if(retorno==1)
			{
				porcentajeAutosPorCaja(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'm':
			if(retorno==1)
			{
				mostrarAutosTipoDeCaja(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'n':
			if(retorno==1)
			{
				cantAutosPorColorYMarca(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'o':
			if(retorno==1)
			{
				mostrarMarcaMasElegida(listaAutos, TAM_A, listaColores, TAM_C, listaMarcas, TAM_M, listaClientes, TAM_CLIENTE);
			}
			else
			{
				printf("\nPrimero debe dar de alta un auto.\n");
			}
			break;
		case 'p':
			printf("\nFin.\n");
			break;
		default:
			printf("\nIngrese una opción válida.\n");
			break;
		}
	}while(opcion!='p');

	return EXIT_SUCCESS;
}
