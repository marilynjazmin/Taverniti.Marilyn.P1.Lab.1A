#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[20];
	float precio;
}eServicio;

/**
 * @fn void mostrarServicio(eServicio)
 * @brief muestra un servicio
 *
 * @param unServicio
 */
void mostrarServicio(eServicio unServicio);

/**
 * @fn void mostrarServicios(eServicio[], int)
 * @brief muestra el array de servicios
 *
 * @param listaServicios vector servicios
 * @param tamS tamaño del vector
 */
void mostrarServicios(eServicio listaServicios[], int tamS);

#endif /* SERVICIO_H_ */
