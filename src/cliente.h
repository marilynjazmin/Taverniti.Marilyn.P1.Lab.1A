#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo;
}eCliente;

int cargarNombreCliente(eCliente listaClientes[], int tamCliente, char descripcion[], int idDescripcion);


#endif /* CLIENTE_H_ */
