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
	printf("J. MOSTRAR AUTOS DE UN COLOR A ELECCIÓN\n");
	printf("K. MOSTRAR AUTOS DE UNA MARCA A ELECCIÓN\n");
	printf("L. MOSTRAR PROMEDIO DE AUTOS CON CAJA MANUAL Y AUTOMÁTICA\n");
	printf("M. MOSTRAR LISTADO DE AUTOS SEPARADOS POR TIPO DE CAJA\n");
	printf("N. MOSTRAR CANTIDAD DE AUTOS DE UN COLOR Y MARCA A ELECCIÓN\n");
	printf("O. MOSTRAR LA O LAS MARCAS MÁS ELEGIDAS\n");
	printf("P. SALIR\n");
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

