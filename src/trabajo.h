#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	int patente;
	int idServicio;
	eFecha fechaTrabajo;
	int isEmpty;
}eTrabajo;

int inicializarListaTrabajos(eTrabajo listaTrabajos[], int tamT);
int buscarEspacioLibreTrabajo(eTrabajo listaTrabajos[], int tamT);
int hardcodeoTrabajos(eTrabajo listaTrabajos[], int tamT, int cant, int* id);

#endif /* TRABAJO_H_ */
