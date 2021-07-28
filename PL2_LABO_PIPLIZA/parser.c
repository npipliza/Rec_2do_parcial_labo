#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eEditoriales.h"

/** \brief Parsea los datos desde el archivo indicado(modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList, eLibros* listadoLibros)
{
    int  bandera = 0;
    char aux_1[50];
	char aux_2[50];
	char aux_3[50];
	char aux_4[50];
	char aux_5[50];

    //lectura fantasma del encabezado
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", aux_1, aux_2, aux_3, aux_4, aux_5);

    while(!feof(pFile))//Mientras no se llege al final del archivo
    {
        int status = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", aux_1, aux_2, aux_3, aux_4, aux_5);

        if(status == 5)//status = a los datos pedidos a leer
        {
            //asigno a this las variables leidas casteadas en la funcion
            eLibros* this = setters(aux_1, aux_2, aux_3, aux_4, aux_5);
            ll_add(pArrayList, this);//Agrego al final del array
            bandera = 1;
        }
    }//fin del while
    fclose(pFile);
    return bandera;
}//fin funcion parser_FromText

/* **************************************************************************************************************** */
/** \brief Parsea los datos desde el archivo indicado (modo binario).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_FromBinary(FILE* pFile, LinkedList* pArrayList)
{
    int bandera = 0;

    while(!feof(pFile))
    {
        eLibros* this = new();
        int status    = fread(this, sizeof(eLibros), 1, pFile);//leer datos del archivo abierto desde la posicion indicada

        if(status == 1 && this != NULL)
        {
            ll_add(pArrayList, this);
        }
        else
        {
        	if(status != 1)
        	{
				if(!feof(pFile)) //Si no llega al final del archivo
				{
					printf("\tATENCIÓN! Error al leer el archivo.");
					break;
				}
				else //Si carga el archivo ok
				{
					printf("\tDatos Cargados exitosamente.\n\n");
					bandera = 1;
				}
        	}
        }//fin else
    }//fin del while
    fclose(pFile); //Cierro el archivo
    return bandera;
}//fin funcion parser_FromBinary
