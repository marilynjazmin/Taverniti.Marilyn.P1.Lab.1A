#include <stdio.h>
#include <stdlib.h>
#include "auto.h"

int inicializarListaAutos(eAuto listaAutos[], int tamA)
{
	int todoOk=0;

	if(listaAutos!=NULL && tamA>0)
	{
		for(int i=0; i<tamA; i++)
		{
			listaAutos[i].isEmpty=DISPONIBLE;
		}
		todoOk=1;
	}

	return todoOk;
}

int hardcodeoAutos(eAuto listaAutos[], int tamA, int cant, int* id)
{
	int todoOk=0;

	eAuto auxLista[4]={{1,1001,5004,'m'},
					   {2,1002,5002,'m'},
					   {3,1000,5003,'m'},
					   {4,1004,5000,'a'}};

	for(int i=0;i<cant;i++)
	{
		auxLista[i].id=*id;
		(*id)++;
		auxLista[i].isEmpty=OCUPADO;
		listaAutos[i]=auxLista[i];
		todoOk=1;
	}

	return todoOk;
}

int buscarEspacioLibre(eAuto listaAutos[], int tamA)
{
	int indice=-1;

	if(listaAutos!=NULL && tamA>0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==DISPONIBLE)
			{
				indice=i;
				break;
			}
		}
	}

	return indice;
}

int validarIdAuto(eAuto listaAutos[], int tamA , int id)
{
	int esValido=-1;

	if(listaAutos!=NULL && tamA>0 && id>0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].id == id)
			{
				esValido=i;
				break;
			}
		}
	}

	return esValido;
}
