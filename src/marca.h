#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

/**
 * @fn int cargarDescripcionMarca(eMarca[], int, char[], int)
 * @brief valida si el id que se ingresó existe en el array de marcas, si existe copia la descripción en la variable pasada por parámetros
 *
 * @param listaMarcas vector de marcas
 * @param tamM tamaño del vector
 * @param descripcion variable pasada por parametros para asignarle la descripción
 * @param idDescripcion campo id de la estructura autos que se valida
 * @return 1 si realizó la función, 0 si no
 */
int cargarDescripcionMarca(eMarca listaMarcas[], int tamM, char descripcion[], int idDescripcion);

/**
 * @fn void mostrarMarca(eMarca)
 * @brief muestra una marca
 *
 * @param marca
 */
void mostrarMarca(eMarca marca);

/**
 * @fn void mostrarMarcas(eMarca[], int)
 * @brief muestra la lista de marcas
 *
 * @param listaMarcas vector de marcas
 * @param tamM tamaño del vector
 */
void mostrarMarcas(eMarca listaMarcas[], int tamM);

/**
 * @fn int validarIdMarca(eMarca[], int, int)
 * @brief valida si el id ingresado por parámetros existe en el array
 *
 * @param listaMarcas vector de marcas
 * @param tamM tamaño del vector
 * @param id variable que se verifica
 * @return devuelve la posición de ese ID si existe, 0 si no existe
 */
int validarIdMarca(eMarca listaMarcas[], int tamM, int id);

#endif /* MARCA_H_ */
