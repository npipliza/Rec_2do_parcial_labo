#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eEditoriales.h"
#include "utn.h"

/* ************************************************************************************************************* */
eLibros* new()
{
    eLibros* this = malloc(sizeof(eLibros)); //Creo un nuevo editorial con memodia dinamica "malloc"
    if(this == NULL)
    {
        printf("ATENCIÓN! Sin lugar para almacenar datos.\n");
        exit(EXIT_FAILURE); //De ser NULL salgo
    }
    else //De lo contrario parseo a 0 y cadena vacia las variables
    {
    	this->idLibro = 0;
        strcpy(this->titulo, "");
        strcpy(this->autor, "");
        this->precio = 0;
        strcpy(this->editorial, "");
    }
    return this; //Retorno el puntero a la estructura creada
}

/* ************************************************************************************************************* */
eLibros* setters(char* idLibro,char* titulo, char* autor, char* precio, char* editorial)
{//asigno los valores
    eLibros* this = new();
    int retorno = 0;

    if(setId(this,atoi(idLibro)))
    {
        retorno = 1;
    }

    if(setTitulo(this,titulo) && retorno)
    {
        retorno = 1;
    }

    if(setAutor(this,autor) && retorno)
    {
        retorno = 1;
    }

    if(setPrecio(this,atof(precio)) && retorno)
    {
        retorno = 1;
    }

    if(setIdEditorial(this,editorial) && retorno)
    {
        retorno = 1;
    }

    if(!retorno)
    {
        printf("\nATENCIÓN! Error al cargar datos, revise la lista.\n");
        free(this);
    }

    return this;
}

/* ************************************************************************************************************* */
int getters(eLibros* this, int* idLibro, char* titulo, char* autor, float* precio, char* editorial)
{
    int retorno = 0;

    if (this != NULL)
    {
        if (getId(this, idLibro))
        {
            retorno = 1;
        }
        if (getTitulo(this, titulo) && retorno)
        {
            retorno = 1;
        }
        if (getAutor(this, autor) && retorno)
        {
            retorno = 1;
        }
        if (getPrecio(this, precio) && retorno)
        {
            retorno = 1;
        }
        if (getIdEditorial(this, editorial) && retorno)
        {
            retorno = 1;
        }
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setId(eLibros* this,int idLibro)
{
    int retorno = 0;

    if(this != NULL && idLibro >= 0)
    {
        this->idLibro = idLibro;
        retorno     = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getId(eLibros* this,int* idLibro)
{
    int retorno = 0;

    if(this != NULL && idLibro != NULL)
    {
        *idLibro  = this->idLibro;
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setTitulo(eLibros* this,char* titulo)
{
    int retorno = 0;

    if(this != NULL)
    {
        strncpy(this->titulo, titulo, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getTitulo(eLibros* this,char* titulo)
{
    int retorno = 0;

    if (this != NULL)
    {
        strncpy(titulo, this->titulo, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setAutor(eLibros* this,char* autor)
{
    int retorno = 0;

    if(this != NULL)
    {
        strncpy(this->autor, autor, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getAutor(eLibros* this,char* autor)
{
    int retorno = 0;

    if (this != NULL)
    {
        strncpy(autor, this->autor, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setIdEditorial(eLibros* this,char* editorial)
{
    int retorno=0;

    if(this != NULL && editorial >= 0)
    {
    	strncpy(this->editorial, editorial, 50);
        retorno     = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getIdEditorial(eLibros* this,char* editorial)
{
    int retorno = 0;

    if (this != NULL)
    {
        strncpy(editorial, this->editorial, 50);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int setPrecio(eLibros* this,float precio)
{
    int retorno=0;
    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        retorno=1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int getPrecio(eLibros* this,float* precio)
{
    int retorno = 0;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        retorno=1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
int mostrarLibros(eLibros* this)
{
    int retorno = 0;
    int idLibro;
    float precio;
    char  titulo[50];
    char  autor[50];
    char  editorial[50];

    if (getters(this, &idLibro, titulo, autor, &precio, editorial))
    {
        printf(" %3d | %50s  | %20s | $%10.2f | %3s \t\t \n", idLibro, titulo, autor, precio, editorial);
        retorno = 1;
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief ordena por id libro idLibro
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (-1) si punteroA menor a punteroB
               (0) si punteroA igual a punteroB
               (1) si punteroA manor a punteroB
               (-2) If NULL pointer
 *
 */
int ordenrPorID(void* punteroA, void* punteroB)
{
    int retorno = -2;

    if(punteroA != NULL && punteroB != NULL)
    {
        int id_A, id_B;

        getId(punteroA, &id_A);
        getId(punteroB, &id_B);

        if((id_A) < (id_B)) //Si idLibro de A en menor que idLibro de B cambio al retorno retorno a 1
        {
            retorno = 1 ;
        }
        else
        {
        	if((id_A) == (id_B)) //Si idLibro de A igual que idLibro de B dejo la retorno igual
        	{
        		retorno = 0;
        	}
			else
			{
				retorno = -1;
			}
        }
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief ordena por nombre Autor
 *
 * \param void* punteroA
 * \param void* punteroB
 * \return int (1) if OK - (0) If NULL pointer
 *
 */
int ordenarPorAutor(void* punteroA, void* punteroB)
{
    int retorno = 1;

    if(punteroA != NULL && punteroB != NULL)
    {
        char aux_A[50];
        char aux_B[50];

        getAutor(punteroA, aux_A);
        getAutor(punteroB, aux_B);
        retorno = strcmp(aux_A, aux_B);
    }
    return retorno;
}

/* ************************************************************************************************************* */
/** \brief Asigna el precio de det libros
 *
 * \param void* this
 * \return Retorna -1 si hay error y si no 0.
 *
 */
void mapPrecio(void* this)
{
    float precio;
    char editorial[50];

    if (this != NULL)
    {
        getIdEditorial(this, editorial);
        getPrecio(this, &precio);

        if(!strcmp(editorial, "PLANETA") && precio >= 300)
        {
            setPrecio(this, precio * 0.8);
        }
        else
        {
        	if(!strcmp(editorial, "SIGLO XXI EDITORES") && precio <= 200)
        	{
        		setPrecio(this, precio * 0.9);
        	}
        }
    }
}

