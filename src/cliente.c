#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int cargarNombreCliente(eCliente listaClientes[], int tamCliente, char descripcion[], int idDescripcion)
{
	int todoOk=0;

	if(listaClientes!=NULL && tamCliente>0 && descripcion!=NULL)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(idDescripcion == listaClientes[i].id)
			{
				strcpy(descripcion, listaClientes[i].nombre);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;
}
