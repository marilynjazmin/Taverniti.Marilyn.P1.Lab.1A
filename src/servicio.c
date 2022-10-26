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

int cargarDescripcionServicio(eServicio listaServicios[], int tamS, char descripcion[], int idDescripcion)
{
	int todoOk=0;

	if(listaServicios!=NULL && tamS>0 && descripcion!=NULL)
	{
		for(int i=0; i<tamS; i++)
		{
			if(idDescripcion == listaServicios[i].id)
			{
				strcpy(descripcion, listaServicios[i].descripcion);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}

int validarIdServicio(eServicio listaServicios[], int tamS, int id)
{
	int esValido=-1;

	if(listaServicios!=NULL && tamS>0 && id>0)
	{
		for(int i=0; i<tamS; i++)
		{
			if(listaServicios[i].id == id)
			{
				esValido=i;
				break;
			}
		}
	}

	return esValido;
}
