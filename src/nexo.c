#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

void mostrarAuto(eAuto unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente)
{
	char descripcionMarca[20];
	char descripcionColor[20];
	char nombreCliente[20];

	cargarDescripcionMarca(listaMarcas, tamM, descripcionMarca, unAuto.idMarca);
	cargarDescripcionColor(listaColores, tamC, descripcionColor, unAuto.idColor);
	cargarNombreCliente(listaClientes, tamCliente, nombreCliente, unAuto.idCliente);

	printf("| %02d  | %-10s  | %-10s|   %c   |  %-10s  |\n", unAuto.id,
												descripcionMarca,
												descripcionColor,
												unAuto.caja,
												nombreCliente);
}

void mostrarAutos(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente)
{
	if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamA>0 && tamM>0 && tamC>0)
	{
		printf("------------------------------------------------------------\n");
		printf("|   ID    |    MARCA    |   COLOR   | CAJA  |  CLIENTE  |\n");
		printf("------------------------------------------------------------\n");
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO)
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
			}
		}
		printf("--------------------------------------------------------------\n");
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

int bajaAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int id;
	int indice;
	char confirmacion;

	if(listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && tamA>0 && tamM>0 && tamC>0)
	{
		mostrarAutos(listaAutos, tamA, listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
		id=pedirNumero("Ingrese ID del auto: ");
		indice=validarIdAuto(listaAutos, tamA, id);
		while(indice==-1)
		{
			id=pedirNumero("ID inexistente. Reingrese ID del auto: ");
			indice=validarIdAuto(listaAutos, tamA, id);
		}

		printf("\nSeleccionó:\n ");
		mostrarAuto(listaAutos[indice], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);

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

int modificarAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int id;
	int indice;
	int opcion;
	char confirmacion='s';
	int auxIdColor;
	int auxIdMarca;

	mostrarAutos(listaAutos, tamA, listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
	id=pedirNumero("Ingrese el ID del auto: ");
	indice=validarIdAuto(listaAutos, tamA, id);
	while(indice==-1)
	{
		id=pedirNumero("ID inexistente. Reingrese el ID del auto: ");
		indice=validarIdAuto(listaAutos, tamA, id);
	}

	printf("\nSeleccionó: \n");
	mostrarAuto(listaAutos[indice], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);

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

void mostrarTrabajo(eTrabajo unTrabajo, eAuto listaAutos[], int tamA, eServicio listaServicios[], int tamS)
{
	//int idAuto;
	char descripcionServicio[20];

	//cargarIdAuto(listaAutos, tamA, idAuto, unTrabajo.patente);
	cargarDescripcionServicio(listaServicios, tamS, descripcionServicio, unTrabajo.idServicio);

	printf("| %02d | %-10d | %-10s | %d/%d/%d |\n", unTrabajo.id,
												unTrabajo.patente,
												descripcionServicio,
												unTrabajo.fechaTrabajo.dia,
												unTrabajo.fechaTrabajo.mes,
												unTrabajo.fechaTrabajo.anio);
}

void mostrarTrabajos(eTrabajo listaTrabajos[], int tamT, eAuto listaAutos[], int tamA, eServicio listaServicios[], int tamS)
{
	if(listaTrabajos!=NULL && listaAutos!=NULL && listaServicios!=NULL && tamT>0 && tamA>0 && tamS>0)
	{
		printf("------------------------------------------------\n");
		printf("|   ID    |   PATENTE  |  SERVICIO  |  FECHA  |\n");
		printf("------------------------------------------------\n");
		for(int i=0; i<tamT; i++)
		{
			if(listaTrabajos[i].id>0)
			{
				mostrarTrabajo(listaTrabajos[i], listaAutos, tamA, listaServicios, tamS);
			}
		}
		printf("---------------------------------------------\n");
		printf("\n");
	}
}

int cargarTrabajo(eTrabajo* unTrabajo, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eServicio listaServicios[], int tamS, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int auxIdAuto;
	int auxIdServicio;
	int auxDia;
	int auxMes;
	int auxAnio;

	if(unTrabajo!=NULL && listaAutos!=NULL && listaServicios!=NULL && tamA>0 && tamS>0)
	{
		mostrarAutos(listaAutos, tamA, listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
		auxIdAuto=pedirNumero("Ingrese ID del auto: ");
		while((validarIdAuto(listaAutos, tamA, auxIdAuto))==-1)
		{
			auxIdAuto=pedirNumero("ID no coincide. Reingrese ID del auto: ");
		}
		unTrabajo->patente=auxIdAuto;

		mostrarServicios(listaServicios, tamS);
		auxIdServicio=pedirNumero("Ingrese el ID del servicio: ");
		while((validarIdServicio(listaServicios, tamS, auxIdServicio))==-1)
		{
			auxIdServicio=pedirNumero("ID no coincide. Reingrese ID del servicio: ");
		}
		unTrabajo->idServicio=auxIdServicio;

		printf("Ingrese fecha \n");
		auxDia=pedirNumero("Ingrese día: ");
		auxMes=pedirNumero("Ingrese mes: ");
		auxAnio=pedirNumero("Ingrese año: ");

		while(validarFecha(auxDia, auxMes, auxAnio)!=1)
		{
			printf("Error. Reingrese fecha \n");
			auxDia=pedirNumero("Ingrese día: ");
			auxMes=pedirNumero("Ingrese mes: ");
			auxAnio=pedirNumero("Ingrese año: ");
		}

		unTrabajo->fechaTrabajo.dia=auxDia;
		unTrabajo->fechaTrabajo.mes=auxMes;
		unTrabajo->fechaTrabajo.anio=auxAnio;

		unTrabajo->isEmpty=OCUPADO;

		todoOk=1;
	}

	return todoOk;
}

int altaTrabajo(int* id, eTrabajo listaTrabajos[], int tamT, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eServicio listaServicios[], int tamS, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int indice;
	eTrabajo auxLista;

	if(listaTrabajos!=NULL && listaAutos!=NULL && listaMarcas!=NULL && listaColores!=NULL && listaServicios!=NULL && tamT>0 && tamA>0 && tamM>0 && tamC>0 && tamS>0)
	{
		indice=buscarEspacioLibreTrabajo(listaTrabajos, tamT);
		if(indice==-1)
		{
			printf("\nNo hay más espacio.\n");
		}
		else
		{
			cargarTrabajo(&auxLista, listaAutos, tamA, listaMarcas, tamM, listaColores, tamC, listaServicios, tamS, listaClientes, tamCliente);
			auxLista.id=*id;
			(*id)++;
			listaTrabajos[indice]=auxLista;
		}
		todoOk=1;
	}

	return todoOk;
}

int validarFecha(int dia, int mes, int anio)
{
	int todoOk=0;
	int valido=0;

	if(mes>=1 && mes<=12)
	{
		switch(mes)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia>0 && dia<32)
			{
				valido=1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia>0 && dia<31)
			{
				valido=1;
			}
			break;
		case 2:
			if(dia>0 && dia<30)
			{
				valido=1;
			}
			break;
		}
	}

	if(valido==1)
	{
		todoOk=1;
	}

	return todoOk;
}

int mostrarAutosColor(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int idColor;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		mostrarColores(listaColores, tamC);
		idColor=pedirNumero("Ingrese el ID del color: ");
		while((validarIdColor(listaColores, tamC, idColor))==-1)
		{
			idColor=pedirNumero("ID no coincide. Reingrese ID del color: ");
		}

		mostrarAutosIdColor(idColor, listaAutos, tamA, listaColores, tamC, listaMarcas, tamM, listaClientes, tamCliente);

		todoOk=1;
	}

	return todoOk;
}

int mostrarAutosIdColor(int idColor, eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	char descripcion[20];
	int flag=1;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		printf("---------------------------------------------\n");
		printf("  PATENTE      MARCA        COLOR     CAJA\n");
		printf("---------------------------------------------\n");

		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].idColor == idColor)
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
				flag=0;
			}
		}
		printf("---------------------------------------------\n");

		if(flag)
		{
			cargarDescripcionColor(listaColores, tamC, descripcion, idColor);
			printf("No hay autos del color %s.\n\n", descripcion);
		}
		todoOk=1;
	}

	return todoOk;
}

int mostrarAutosMarca(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int idMarca;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		mostrarMarcas(listaMarcas, tamM);
		idMarca=pedirNumero("Ingrese el ID de la marca: ");
		while((validarIdMarca(listaMarcas, tamM, idMarca))==-1)
		{
			idMarca=pedirNumero("ID no coincide. Reingrese ID de la marca: ");
		}

		mostrarAutosIdMarca(idMarca, listaAutos, tamA, listaColores, tamC, listaMarcas, tamM, listaClientes, tamCliente);

		todoOk=1;
	}

	return todoOk;
}

int mostrarAutosIdMarca(int idMarca, eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	char descripcion[20];
	int flag=1;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		printf("---------------------------------------------\n");
		printf("  PATENTE      MARCA        COLOR     CAJA\n");
		printf("---------------------------------------------\n");

		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].idMarca == idMarca)
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
				flag=0;
			}
		}
		printf("---------------------------------------------\n");

		if(flag)
		{
			cargarDescripcionMarca(listaMarcas, tamM, descripcion, idMarca);
			printf("No hay autos de la marca %s.\n\n", descripcion);
		}
		todoOk=1;
	}

	return todoOk;
}

int mostrarMarcaMasElegida(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int contadorMarca[]={0,0,0,0,0};
	int marcaMasElegida;
	char descripcionMarca[20];

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		for(int i=0; i<tamM; i++)
		{
			for(int j=0; j<tamA; j++)
			{
				if(listaAutos[j].isEmpty == OCUPADO && listaAutos[j].idMarca == listaMarcas[i].id)
				{
					contadorMarca[i]++;
				}
			}

			for(int i=0; i<tamM; i++)
			{
				if(i==0 || contadorMarca[i]>marcaMasElegida)
				{
					marcaMasElegida=contadorMarca[i];
				}
			}

			if(i==0 || contadorMarca[i]==marcaMasElegida)
			{
				cargarDescripcionMarca(listaMarcas, tamM, descripcionMarca, listaMarcas[i].id);
				printf("La marca más elegida es: %s\n", descripcionMarca);
			}
		}
		todoOk=1;
	}


	return todoOk;
}

int mostrarAutosTipoDeCaja(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		printf("Caja: MANUAL\n");
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].caja == 'm')
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
			}
		}
		printf("\n------------------------------------------------\n");

		printf("Caja: AUTOMÁTICA\n");
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].caja == 'a')
			{
				mostrarAuto(listaAutos[i], listaMarcas, tamM, listaColores, tamC, listaClientes, tamCliente);
			}
		}
		printf("\n------------------------------------------------\n");

		todoOk=1;
	}

	return todoOk;
}

int porcentajeAutosPorCaja(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente)
{
	int todoOk=0;
	int contadorCajaM=0;
	float porcentajeCajaM;
	int contadorCajaA=0;
	float porcentajeCajaA;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].caja == 'm')
			{
				contadorCajaM++;
			}
			else
			{
				if(listaAutos[i].isEmpty==OCUPADO && listaAutos[i].caja == 'a')
				{
					contadorCajaA++;
				}
			}
		}
		todoOk=1;

		porcentajeCajaM=contadorCajaM*tamA/100;
		porcentajeCajaA=contadorCajaA*tamA/100;

		printf("\nEl porcentaje de autos con caja manual es de: %.2f\n", porcentajeCajaM);
		printf("\nEl porcentaje de autos con caja automática es de: %.2f\n", porcentajeCajaA);
	}

	return todoOk;
}

int cantAutosPorColorYMarca(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM)
{
	int todoOk=0;
	int idMarca;
	int idColor;
	int contadorMarca=0;
	int contadorColor=0;

	if(listaAutos!=NULL && listaColores!=NULL && listaMarcas!=NULL && tamA>0 && tamC>0 && tamM>0)
	{
		mostrarMarcas(listaMarcas, tamM);
		idMarca=pedirNumero("Ingrese el ID de la marca: ");
		while((validarIdMarca(listaMarcas, tamM, idMarca))==-1)
		{
			idMarca=pedirNumero("ID no coincide. Reingrese ID de la marca: ");
		}

		mostrarColores(listaColores, tamC);
		idColor=pedirNumero("Ingrese el ID del color: ");
		while((validarIdColor(listaColores, tamC, idColor))==-1)
		{
			idColor=pedirNumero("ID no coincide. Reingrese ID del color: ");
		}

		for(int j=0; j<tamA; j++)
		{
			if(listaAutos[j].isEmpty==OCUPADO && listaAutos[j].idMarca==idMarca)
			{
				contadorMarca++;
			}
		}
		printf("\nCantidad de autos por la marca seleccionada: %d", contadorMarca);

		for(int j=0; j<tamA; j++)
		{
			if(listaAutos[j].isEmpty==OCUPADO && listaAutos[j].idColor==idColor)
			{
				contadorColor++;
			}
		}
		printf("\nCantidad de autos por el color seleccionado: %d\n\n", contadorColor);

		todoOk=1;
	}

	return todoOk;
}


