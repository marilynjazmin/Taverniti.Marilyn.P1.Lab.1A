#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

void mostrarAuto(eAuto unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	char descripcionMarca[20];
	char descripcionColor[20];

	cargarDescripcionMarca(listaMarcas, tamM, descripcionMarca, unAuto.idMarca);
	cargarDescripcionColor(listaColores, tamC, descripcionColor, unAuto.idColor);

	printf("| %02d  | %-10s  | %-10s|   %c   |\n", unAuto.id,
												descripcionMarca,
												descripcionColor,
												unAuto.caja);
}

void mostrarAutos(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamA>0 && tamM>0 && tamC>0)
	{
		printf("---------------------------------------------\n");
		printf("|   ID    |    MARCA    |   COLOR   | CAJA  |\n");
		printf("---------------------------------------------\n");
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO)
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC);
			}
		}
		printf("---------------------------------------------\n");
		printf("\n");
	}
}

int cargarAuto(eAuto* unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	int todoOk=0;
	int auxIdMarca;
	int auxIdColor;

	if(unAuto!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamM>0 && tamC>0)
	{
		mostrarMarcas(listaMarcas, tamM);
		auxIdMarca=pedirNumero("Ingrese ID de la marca: ");
		while((validarIdMarca(listaMarcas, tamM, auxIdMarca))==-1)
		{
			auxIdMarca=pedirNumero("ID no coincide. Reingrese ID de la marca: ");
		}
		unAuto->idMarca=auxIdMarca;

		mostrarColores(listaColores, tamC);
		auxIdColor=pedirNumero("Ingrese el ID del color: ");
		while((validarIdColor(listaColores, tamC, auxIdColor))==-1)
		{
			auxIdColor=pedirNumero("ID no coincide. Reingrese ID del color: ");
		}
		unAuto->idColor=auxIdColor;

		printf("Ingrese el tipo de caja: \n'm'(manual)/ 'a'(automático): ");
		fflush(stdin);
		scanf("%c", &unAuto->caja);

		unAuto->isEmpty=OCUPADO;

		todoOk=1;
	}

	return todoOk;
}

int altaAuto(int* id, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	int todoOk=0;
	int indice;
	eAuto auxLista;

	if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamA>0 && tamM>0 && tamC>0)
	{
		indice=buscarEspacioLibre(listaAutos, tamA);
		if(indice==-1)
		{
			printf("\nNo hay más espacio.\n");
		}
		else
		{
			cargarAuto(&auxLista, listaMarcas, tamM, listaColores, tamC);
			auxLista.id=*id;
			(*id)++;
			listaAutos[indice]=auxLista;
		}
		todoOk=1;
	}

	return todoOk;
}

int bajaAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	int todoOk=0;
	int id;
	int indice;
	char confirmacion;

	if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamA>0 && tamM>0 && tamC>0)
	{
		mostrarAutos(listaAutos, tamA, listaMarcas, tamM, listaColores, tamC);
		id=pedirNumero("Ingrese ID del auto: ");
		indice=validarIdAuto(listaAutos, tamA, id);
		while(indice==-1)
		{
			id=pedirNumero("ID inexistente. Reingrese ID del auto: ");
			indice=validarIdAuto(listaAutos, tamA, id);
		}

		printf("\nSeleccionó:\n ");
		mostrarAuto(listaAutos[indice], listaMarcas, tamM, listaColores, tamC);

		printf("¿Confirma? s/n: ");
		fflush(stdin);
		scanf("%c", &confirmacion);
		if(confirmacion=='s')
		{
			listaAutos[indice].isEmpty=DISPONIBLE;
		}
	}
		todoOk=1;

	return todoOk;
}

int modificarAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC)
{
	int todoOk=0;
	int id;
	int indice;
	int opcion;
	char confirmacion='s';
	int auxIdColor;
	int auxIdMarca;

	mostrarAutos(listaAutos, tamA, listaMarcas, tamM, listaColores, tamC);
	id=pedirNumero("Ingrese el ID del auto: ");
	indice=validarIdAuto(listaAutos, tamA, id);
	while(indice==-1)
	{
		id=pedirNumero("ID inexistente. Reingrese el ID del auto: ");
		indice=validarIdAuto(listaAutos, tamA, id);
	}

	printf("\nSeleccionó: \n");
	mostrarAuto(listaAutos[indice], listaMarcas, tamM, listaColores, tamC);

	do
	{
		opcion=subMenuModificaciones();
		switch(opcion)
		{
		case 1:
			mostrarColores(listaColores, tamC);
			pedirEntero(&auxIdColor, "\nIngrese ID de un color: ", "Error. Reingrese ID de un color: ", 5000, 5004);
			while((validarIdColor(listaColores, tamC, auxIdColor))==-1)
			{
				auxIdColor=pedirNumero("ID no coincide. Reingrese ID del color: ");
			}
			pedirCaracter(&confirmacion, "Confirme s/n: ", "Error, ingrese una letra: ");
			if(confirmacion=='s')
			{
				listaAutos[indice].idColor=auxIdColor;
				printf("\nModificación realizada.\n");
			}
			else
			{
				printf("\nModificación cancelada.\n");
			}
			break;
		case 2:
			mostrarMarcas(listaMarcas, tamM);
			pedirEntero(&auxIdMarca, "\nIngrese ID de una marca: ", "Error. Reingrese ID de una marca: ", 1000, 1004);
			while((validarIdMarca(listaMarcas, tamM, auxIdMarca))==-1)
			{
				auxIdMarca=pedirNumero("ID no coincide. Reingrese ID de la marca: ");
			}
			pedirCaracter(&confirmacion, "Confirme s/n: ", "Error, ingrese una letra: ");
			if(confirmacion=='s')
			{
				listaAutos[indice].idMarca=auxIdMarca;
				printf("\nModificación realizada.\n");
			}
			else
			{
				printf("\nModificación cancelada.\n");
			}
			break;
		case 3:
			printf("\n");
			break;
		default:
			printf("Error. Reingrese una opción válida.\n");
			break;
		}
	}while(opcion!=3);

	return todoOk;
}

int listarAutosPorMarca(eAuto listaAutos[], int tamA)
{
	int todoOk=0;
	eAuto aux;

	if(listaAutos!=NULL && tamA>0)
	{
		for(int i=0;i<tamA-1;i++)
		{
			for(int j=i+1;j<tamA;j++)
			{
				if(listaAutos[i].idMarca>listaAutos[j].idMarca)
				{
					aux=listaAutos[i];
					listaAutos[i]=listaAutos[j];
					listaAutos[j]=aux;
				}
			}
		}
		todoOk=1;
	}

	return todoOk;
}

