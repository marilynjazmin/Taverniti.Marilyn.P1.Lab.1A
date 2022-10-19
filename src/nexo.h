#ifndef NEXO_H_
#define NEXO_H_
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "input.h"
#include "menu.h"

/**
 * @fn void mostrarAuto(eAuto, eMarca[], int, eColor[], int)
 * @brief muestra un auto
 *
 * @param unAuto una posici�n
 * @param listaMarcas vector de marcas
 * @param tamM tama�o del vector marcas
 * @param listaColores vector de colores
 * @param tamC tama�o del vector colores
 */
void mostrarAuto(eAuto unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn void mostrarAutos(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief muestra la lista de autos
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector autos
 * @param listaMarcas vector de marcas
 * @param tamM tama�o del vector marcas
 * @param listaColores vector de colores
 * @param tamC tama�o del vector colores
 */
void mostrarAutos(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int cargarAuto(eAuto*, eMarca[], int, eColor[], int)
 * @brief pide datos
 *
 * @param unAuto
 * @param listaMarcas
 * @param tamM
 * @param listaColores
 * @param tamC
 * @return
 */
int cargarAuto(eAuto* unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int altaAuto(int*, eAuto[], int, eMarca[], int, eColor[], int)
 * @brief busca espacio en el array y si hay, llama a otra funci�n para pedir datos y los guarda
 *
 * @param id entero pasado por par�metros con un valor para que el id se autoincremente a partir de ese valor cada vez que se da de alta un auto
 * @param listaAutos vector autos
 * @param tamA tama�o vector autos
 * @param listaMarcas vector marcas
 * @param tamM tama�o vector marcas
 * @param listaColores vector colores
 * @param tamC tama�o vector colores
 * @return 1 si realiz� la funci�n, 0 si no
 */
int altaAuto(int* id, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int bajaAuto(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief da de baja un auto cuando se pide el id y lo valida
 *
 * @param listaAutos vector autos
 * @param tamA tama�o del vector autos
 * @param listaMarcas vector marcas
 * @param tamM tama�o del vector marcas
 * @param listaColores vector colores
 * @param tamC tama�o del vector colores
 * @return 1 si realiz� la funci�n, 0 si no
 */
int bajaAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int modificarAuto(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief pide un id al usuario y si existe le muestra el men� para que elija la opci�n que desea modificar
 *
 * @param listaAutos vector autos
 * @param tamA tama�o del vector autos
 * @param listaMarcas vector marcas
 * @param tamM tama�o del vector marcas
 * @param listaColores vector colores
 * @param tamC tama�o del vector colores
 * @return 1 si realiz� la funci�n, 0 si no
 */
int modificarAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int listarAutosPorMarca(eAuto[], int)
 * @brief muestra los autos ordenados por ID de marca
 *
 * @param listaAutos vector de autos
 * @param tamA tama�o del vector autos
 * @return devuelve 1 si realiz� la funci�n, 0 si no
 */
int listarAutosPorMarca(eAuto listaAutos[], int tamA);

#endif /* NEXO_H_ */
