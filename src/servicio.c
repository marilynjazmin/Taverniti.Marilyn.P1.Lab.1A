#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio unServicio)
{
	printf("| %02d | %-15s |  %.2f\n", unServicio.id,
								 unServicio.descripcion,
								 unServicio.precio);
}

void mostrarServicios(eServicio listaServicios[], int tamS)
{
	if(listaServicios!=NULL && tamS>0)
	{
		printf("--------------------------------------\n");
		printf("|  ID  |  DESCRIPCIÓN   |   PRECIO  |\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tamS; i++)
		{
			mostrarServicio(listaServicios[i]);
		}
		printf("------------------------------------\n");
		printf("\n");
	}
}
