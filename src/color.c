#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int cargarDescripcionColor(eColor listaColores[], int tamC, char descripcion[], int idDescripcion)
{
	int todoOk=0;

	if(listaColores!=NULL && tamC>0 && descripcion!=NULL)
	{
		for(int i=0; i<tamC; i++)
		{
			if(idDescripcion == listaColores[i].id)
			{
				strcpy(descripcion, listaColores[i].nombreColor);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}

void mostrarColor(eColor color)
{
	printf("| %02d | %-15s |\n", color.id,
								 color.nombreColor);
}

void mostrarColores(eColor listaColores[], int tamC)
{
	if(listaColores!=NULL && tamC>0)
	{
		printf("-------------------------\n");
		printf("|  ID  |  DESCRIPCIÓN   |\n");
		printf("-------------------------\n");

		for(int i=0; i<tamC; i++)
		{
			mostrarColor(listaColores[i]);
		}
		printf("--------------------------\n");
		printf("\n");
	}
}

int validarIdColor(eColor listaColores[], int tamC, int id)
{
	int esValido=-1;

	if(listaColores!=NULL && tamC>0 && id>0)
	{
		for(int i=0; i<tamC; i++)
		{
			if(listaColores[i].id == id)
			{
				esValido=i;
				break;
			}
		}
	}

	return esValido;
}
