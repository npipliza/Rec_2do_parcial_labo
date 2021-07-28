/*
 * utn.h
 *
 *  Created on: 15 may. 2021
 *      Author: npipliza
 */

#ifndef TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_
#define TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/* ************************************************************************************************************** */
/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

/* ************************************************************************************************************** */
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud);

/* ************************************************************************************************************** */
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena, int limite);

/* ************************************************************************************************************** */
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getFloat(float* pResultado);

/* ************************************************************************************************************** */
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena, int limite);

/* ************************************************************************************************************** */
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int* pResultado);

/* ************************************************************************************************************** */
/**
 * @fn int esString(char*, int)
 * @brief
 * verifica si la cadena ingresada es string
 * @param cadena cadena de caracteres a ser analizada
 * @param longitud longitud maxima de la cadena
 * @return retorna 1 si la cadena es una cadena de caracteres, 0 si no lo es
 */
int esString(char* cadena, int longitud);

/* ************************************************************************************************************** */
/**
 * @fn int getString(char*, int)
 * @brief
 * obtiene una cadena de caracteres
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getString(char* pResultado, int longitud);

/* ************************************************************************************************************** */
/**
 * @fn int utn_getString(char*, int, char[], char[], int)
 * @brief
 * solicita una cadena al usuario, luego de verificarlo devuelve el resultado
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud longitud maxima de la cadena
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje a mostrar en caso de error
 * @param reintentos numero de veces que el usuario puede volver a intentar
 * ingresar la cadena en caso de error
 * @return retorna 0 si se obtuvo una cadena y -1 si no
 */
int utn_getString(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos);

/* ************************************************************************************************************** */
/**
 * @fn int getPalabra(char*, int)
 * @brief
 * obtiene una cadena de caracteres sin posibilidad de añadir espacios entre los mismos
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @return retorna 0 si se obtiene una cadena de caracteres, -1 si no
 */
int getPalabra(char* pResultado,int longitud);

/* ************************************************************************************************************** */
/**
 * @fn int esPalabra(char*, int)
 * @brief
 * verifica si la cadena ingresada es string sin espacios
 * @param palabra cadena de caracteres a ser analizada
 * @param longitud tamaño maximo de la cadena
 * @return retorna 0 si obtiene una cadena de caracteres, -1 si no
 */
int esPalabra(char* palabra, int longitud);

/* ************************************************************************************************************** */
/**
 * @fn int utn_getPalabra(char*, int, char[], char[], int)
 * @brief
 * solicita una cadena de caracteres al usuario(sin espacios), luego de verificarla devuelve el resultado
 * @param pResultado puntero a la direccion de memoria donde se guardara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @param mensaje mensaje que se mostrara al usuario
 * @param mensajeError mensaje que se mostrara al usuario en caso de error
 * @param reintentos cantidad de veces que el usuario puede reintentar en caso de error
 * @return retorna 0 si obtiene una cadena de caracteres, -1 si no
 */
int utn_getPalabra(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos);

/* ************************************************************************************************************** */
/**
 * @fn int PedirEntero(char[], char[])
 * @brief
 *
 * @param mensaje
 * @param mensajeError
 * @return
 */int PedirEntero(char mensaje[]);

 /* ************************************************************************************************************** */
/** \brief valida que lo que se ingresa sea un  numero
 * \param input a validar
 * \return int si solo se ingreseo una numero [0] si no [-1]
 */
int validarNumero(char* numeroChar);

/* ************************************************************************************************************** */
/** \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char* Cadena de caracteres a ser analizada
 * \param longitud int Longitud maxima que debe tener la cadena
 * \return int [1] si la cadena es valida,  [0] si no lo es
 */
int validarNombre(char* cadena,int longitud);

/* ************************************************************************************************************** */
/** \brief Valida que un numero esté dentro de determinado rango
 * \param dato int Numero a ser analizado
 * \param lowLimit int Valor minimo aceptado
 * \param hiLimit int Valor maximo aceptado
 * \return int [1] si esta dentro del rango,  [0] si no lo esta
 */
int validarRangoEntero(int dato,int lowLimit ,int hiLimit);

/* ************************************************************************************************************** */
/** \brief Pide un nombre al usuario y valida que cumpla con las caracteristicas que debe tener un nombre
 * \param [] char El mensaje para pedirle un nombre al usuario
 * \param [] char El mensaje en caso de error
 * \param int El valor maximo que soporta el array de caracteres que albergara el nombre
 * \param [] char El array donde se guardara el array de caracteres
 * \return void
 */
void pedirNombre(char [],char [],int , char []);

/* ************************************************************************************************************** */
/** \brief Pide un numero al usuario, valida y notifica en caso de que no sea un numero, o no este dentro del rango establecido
 * \param input int* Donde se guardará el numero solicitado
 * \param message[] char El mensaje solicitando el numero
 * \param eMessage1[] char  El mensaje de error en caso de que se ingrese alguna letra
 * \param lowLimit int El valor minimo que puede tener el numero ingresado
 * \param hiLimit int El valor maximo que puede tener el numero ingresado
 * \return void
 */
void get_ValidarInt(int* input, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit);

/* ************************************************************************************************************** */
/** * \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage1 Es el mensaje a ser mostrado en caso de que no sea un numero
* \param eMessage2 Es el mensaje a ser mostrado en caso de que no este dentro del rango
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* */
void inputs_getAndValidateInt(int* valor, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit);


#endif /* TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_ */
