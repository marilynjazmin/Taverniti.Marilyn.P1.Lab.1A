#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

int cargarDescripcionMarca(eMarca listaMarcas[], int tamM, char descripcion[], int idDescripcion)
{
	int todoOk=0;

	if(listaMarcas!=NULL && tamM>0 && descripcion!=NULL)
	{
		for(int i=0; i<tamM; i++)
		{
			if(idDescripcion == listaMarcas[i].id)
			{
				strcpy(descripcion, listaMarcas[i].descripcion);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}

void mostrarMarca(eMarca marca)
{
	printf("| %02d | %-15s |\n", marca.id,
								 marca.descripcion);
}

void mostrarMarcas(eMarca listaMarcas[], int tamM)
{
	if(listaMarcas!=NULL && tamM>0)
	{
		printf("-------------------------\n");
		printf("|  ID  |  DESCRIPCIÓN   |\n");
		printf("-------------------------\n");

		for(int i=0; i<tamM; i++)
		{
			mostrarMarca(listaMarcas[i]);
		}
		printf("--------------------------\n");
		printf("\n");
	}
}

int validarIdMarca(eMarca listaMarcas[], int tamM, int id)
{
	int esValido=-1;

	if(listaMarcas!=NULL && tamM>0 && id>0)
	{
		for(int i=0; i<tamM; i++)
		{
			if(listaMarcas[i].id == id)
			{
				esValido=i;
				break;
			}
		}
	}

	return esValido;
}
