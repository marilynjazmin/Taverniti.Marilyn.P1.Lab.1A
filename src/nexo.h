#ifndef NEXO_H_
#define NEXO_H_
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "trabajo.h"
#include "servicio.h"
#include "input.h"
#include "menu.h"
#include "cliente.h"

/**
 * @fn void mostrarAuto(eAuto, eMarca[], int, eColor[], int)
 * @brief muestra un auto
 *
 * @param unAuto una posición
 * @param listaMarcas vector de marcas
 * @param tamM tamaño del vector marcas
 * @param listaColores vector de colores
 * @param tamC tamaño del vector colores
 */
void mostrarAuto(eAuto unAuto, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente);

/**
 * @fn void mostrarAutos(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief muestra la lista de autos
 *
 * @param listaAutos vector de autos
 * @param tamA tamaño del vector autos
 * @param listaMarcas vector de marcas
 * @param tamM tamaño del vector marcas
 * @param listaColores vector de colores
 * @param tamC tamaño del vector colores
 */
void mostrarAutos(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente);

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
 * @brief busca espacio en el array y si hay, llama a otra función para pedir datos y los guarda
 *
 * @param id entero pasado por parámetros con un valor para que el id se autoincremente a partir de ese valor cada vez que se da de alta un auto
 * @param listaAutos vector autos
 * @param tamA tamaño vector autos
 * @param listaMarcas vector marcas
 * @param tamM tamaño vector marcas
 * @param listaColores vector colores
 * @param tamC tamaño vector colores
 * @return 1 si realizó la función, 0 si no
 */
int altaAuto(int* id, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC);

/**
 * @fn int bajaAuto(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief da de baja un auto cuando se pide el id y lo valida
 *
 * @param listaAutos vector autos
 * @param tamA tamaño del vector autos
 * @param listaMarcas vector marcas
 * @param tamM tamaño del vector marcas
 * @param listaColores vector colores
 * @param tamC tamaño del vector colores
 * @return 1 si realizó la función, 0 si no
 */
int bajaAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente);

/**
 * @fn int modificarAuto(eAuto[], int, eMarca[], int, eColor[], int)
 * @brief pide un id al usuario y si existe le muestra el menú para que elija la opción que desea modificar
 *
 * @param listaAutos vector autos
 * @param tamA tamaño del vector autos
 * @param listaMarcas vector marcas
 * @param tamM tamaño del vector marcas
 * @param listaColores vector colores
 * @param tamC tamaño del vector colores
 * @return 1 si realizó la función, 0 si no
 */
int modificarAuto(eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eCliente listaClientes[], int tamCliente);

/**
 * @fn int listarAutosPorMarca(eAuto[], int)
 * @brief muestra los autos ordenados por ID de marca
 *
 * @param listaAutos vector de autos
 * @param tamA tamaño del vector autos
 * @return devuelve 1 si realizó la función, 0 si no
 */
int listarAutosPorMarca(eAuto listaAutos[], int tamA);

void mostrarTrabajo(eTrabajo unTrabajo, eAuto listaAutos[], int tamA, eServicio listaServicios[], int tamS);

void mostrarTrabajos(eTrabajo listaTrabajos[], int tamT, eAuto listaAutos[], int tamA, eServicio listaServicios[], int tamS);

int cargarTrabajo(eTrabajo* unTrabajo, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eServicio listaServicios[], int tamS, eCliente listaClientes[], int tamCliente);

int altaTrabajo(int* id, eTrabajo listaTrabajos[], int tamT, eAuto listaAutos[], int tamA, eMarca listaMarcas[], int tamM, eColor listaColores[], int tamC, eServicio listaServicios[], int tamS, eCliente listaClientes[], int tamCliente);

int validarFecha(int dia, int mes, int anio);

int mostrarAutosColor(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int mostrarAutosIdColor(int idColor, eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int mostrarAutosMarca(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int mostrarAutosIdMarca(int idMarca, eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int mostrarAutosTipoDeCaja(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int cantAutosPorColorYMarca(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM);

int porcentajeAutosPorCaja(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

int mostrarMarcaMasElegida(eAuto listaAutos[], int tamA, eColor listaColores[], int tamC, eMarca listaMarcas[], int tamM, eCliente listaClientes[], int tamCliente);

#endif /* NEXO_H_ */
