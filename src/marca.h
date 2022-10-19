#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

/**
 * @fn int cargarDescripcionMarca(eMarca[], int, char[], int)
 * @brief valida si el id que se ingres� existe en el array de marcas, si existe copia la descripci�n en la variable pasada por par�metros
 *
 * @param listaMarcas vector de marcas
 * @param tamM tama�o del vector
 * @param descripcion variable pasada por parametros para asignarle la descripci�n
 * @param idDescripcion campo id de la estructura autos que se valida
 * @return 1 si realiz� la funci�n, 0 si no
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
 * @param tamM tama�o del vector
 */
void mostrarMarcas(eMarca listaMarcas[], int tamM);

/**
 * @fn int validarIdMarca(eMarca[], int, int)
 * @brief valida si el id ingresado por par�metros existe en el array
 *
 * @param listaMarcas vector de marcas
 * @param tamM tama�o del vector
 * @param id variable que se verifica
 * @return devuelve la posici�n de ese ID si existe, 0 si no existe
 */
int validarIdMarca(eMarca listaMarcas[], int tamM, int id);

#endif /* MARCA_H_ */
