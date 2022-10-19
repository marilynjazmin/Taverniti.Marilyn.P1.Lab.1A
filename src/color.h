#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
	int id;
	char nombreColor[20];
}eColor;

/**
 * @fn int cargarDescripcionColor(eColor[], int, char[], int)
 * @brief valida si el id que se ingres� existe en el array de colores, si existe copia la descripci�n en la variable pasada por par�metros
 *
 * @param listaColores vector de colores
 * @param tamC tama�o del vector
 * @param descripcion variable pasada por parametros para asignarle la descripci�n
 * @param idDescripcion campo id de la estructura autos que se valida
 * @return 1 si realiz� la funci�n, 0 si no
 */
int cargarDescripcionColor(eColor listaColores[], int tamC, char descripcion[], int idDescripcion);

/**
 * @fn void mostrarColor(eColor)
 * @brief muestra un color
 *
 * @param color
 */
void mostrarColor(eColor color);

/**
 * @fn void mostrarColores(eColor[], int)
 * @brief muestra la lista de colores
 *
 * @param listaColores vector de colores
 * @param tamC tama�o del vector
 */
void mostrarColores(eColor listaColores[], int tamC);

/**
 * @fn int validarIdColor(eColor[], int, int)
 * @brief valida si el id ingresado por par�metros existe en el array
 *
 * @param listaColores vector de colores
 * @param tamC tama�o del vector
 * @param id variable que se verifica
 * @return devuelve la posici�n de ese ID si existe, 0 si no existe
 */
int validarIdColor(eColor listaColores[], int tamC, int id);

#endif /* COLOR_H_ */
