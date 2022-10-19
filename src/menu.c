#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menuPrincipal()
{
	char opcion;

	printf("    *** MENU PRINCIPAL ***\n");
	printf("A. ALTA AUTO\n");
	printf("B. MODIFICAR AUTO\n");
	printf("C. BAJA AUTO\n");
	printf("D. LISTAR AUTOS POR ID MARCA\n");
	printf("E. LISTAR MARCAS\n");
	printf("F. LISTAR COLORES\n");
	printf("G. LISTAR SERVICIOS\n");
	printf("H. ALTA TRABAJO\n");
	printf("I. LISTAR TRABAJOS\n");
	printf("J. SALIR\n");
	fflush(stdin);
	scanf("%c", &opcion);

	return opcion;
}

int subMenuModificaciones()
{
	int opcion;

	printf("\n");
	printf("    *** MODIFICACIONES ***\n");
	printf("1. COLOR\n");
	printf("2. MODELO\n");
	printf("3. VOLVER AL MENÚ PRINCIPAL\n");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

