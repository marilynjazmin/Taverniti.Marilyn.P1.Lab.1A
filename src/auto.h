#ifndef AUTO_H_
#define AUTO_H_
#define DISPONIBLE 1
#define OCUPADO 0

typedef struct
{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int idCliente;
	int isEmpty;
}eAuto;

/**
 * @fn int inicializarListaAutos(eAuto[], int)
 * @brief inicializa todas las posiciones del array en 0
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector
 * @return 1 si realiz� la funci�n, 0 si no
 */
int inicializarListaAutos(eAuto listaAutos[], int tamA);

/**
 * @fn int hardcodeoAutos(eAuto[], int, int, int*)
 * @brief hardcodea los datos, recorre el array de acuerdo a las veces que uno le pase por par�metro y asigna un id
 * autoincrimental apartir del n�mero que se le pase por par�metros
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector
 * @param cant tama�o que se pasa por par�metro, indica la cantidad de posiciones que se quiere hardcodear
 * @param id variable autoincremental que se pasa por referencia
 * @return devuelve 1 si realiz� la funci�n, 0 si no
 */
int hardcodeoAutos(eAuto listaAutos[], int tamA, int cant, int* id);

/**
 * @fn int buscarEspacioLibre(eAuto[], int)
 * @brief busca espacio libre en el array de autos
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector
 * @return devuelve una posici�n del vector, o -1 si no encontr� espacio
 */
int buscarEspacioLibre(eAuto listaAutos[], int tamA);

/**
 * @fn int validarIdAuto(eAuto[], int, int)
 * @brief valida si el id existe en el array cargado
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector
 * @param id par�metro que se valida
 * @return devuelve la posici�n de ese ID si existe, 0 si no existe
 */
int validarIdAuto(eAuto listaAutos[], int tamA , int id);


#endif /* AUTO_H_ */
