#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#define DISPONIBLE 1
#define OCUPADO 0

int inicializarListaTrabajos(eTrabajo listaTrabajos[], int tamT)
{
	int todoOk=0;

	if(listaTrabajos!=NULL && tamT>0)
	{
		for(int i=0; i<tamT; i++)
		{
			listaTrabajos[i].isEmpty=DISPONIBLE;
		}
		todoOk=1;
	}

	return todoOk;
}

int hardcodeoTrabajos(eTrabajo listaTrabajos[], int tamT, int cant, int* id)
{
	int todoOk=0;

	eTrabajo auxLista[1]={{1,666002,20001,{1,10,2000},OCUPADO}};

	for(int i=0;i<cant;i++)
	{
		auxLista[i].id=*id;
		(*id)++;
		auxLista[i].isEmpty=OCUPADO;
		listaTrabajos[i]=auxLista[i];
		todoOk=1;
	}

	return todoOk;
}

int buscarEspacioLibreTrabajo(eTrabajo listaTrabajos[], int tamT)
{
	int indice=-1;

	if(listaTrabajos!=NULL && tamT>0)
	{
		for(int i=0; i<tamT; i++)
		{
			if(listaTrabajos[i].isEmpty==DISPONIBLE)
			{
				indice=i;
				break;
			}
		}
	}

	return indice;
}
