#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>


int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}

			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/* ******************************************************************************************************************************** */
int esNumerica(char* cadena, int limite)
{
	int retorno = 1; //verdadero
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/* ******************************************************************************************************************************** */
int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(	pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atof(bufferString) ;
	}
	return retorno;

    return retorno;
}

/* ******************************************************************************************************************************** */
int esFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int i;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] == '.')
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}

		}
	return retorno;
}

/* ******************************************************************************************************************************** */
int utn_getNumeroFlotante(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
		int bufferFloat;
		do
		{
			printf("%s",mensaje);
			if(	getInt(&bufferFloat) == 0 &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	return retorno;
}

/* ******************************************************************************************************************************** */
int esString(char* cadena, int longitud)
{
	int i;
	int retorno = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ' && cadena[i] != '.' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int getString(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esString(buffer, sizeof(buffer)) == 0 && strnlen(buffer,sizeof(buffer)) < longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int utn_getString(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos >=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getString(bufferString, sizeof(bufferString))== 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError );
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
//int esNombre(char* palabra, int longitud)
/*void pedirNombre(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];
    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    while(!validarNombre(auxiliar, max) || strlen(auxiliar) > max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
    }
    strcpy(input, auxiliar);*/
int esNombre(char texto[], char textoError[], int longitud, char* input)
{
	int i = 0;
	int retorno;
	retorno = -1;

	if(input != NULL && longitud > 0)
	{
		for(i=0;i<longitud && input[i] != '\0' ;i++)
		{
			if((input[i] != ' ') && (input[i] < 'A' || input[i] > 'Z') && (input[i] < 'a' || input[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
/* ******************************************************************************************************************************** */
int esPalabra(char* palabra, int longitud)
{
	int i = 0;
	int retorno;
	retorno = -1;

	if(palabra != NULL && longitud > 0)
	{
		for(i=0;i<longitud && palabra[i] != '\0' ;i++)
		{
			if((palabra[i] != ' ' ) && (palabra[i] < 'A' || palabra[i] > 'Z') && (palabra[i] < 'a' || palabra[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int getPalabra(char* pResultado,int longitud)
{
	int retorno =-1;
	char buffer[4096];
	if(pResultado != NULL && longitud > 0)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esPalabra(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer)) < longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int utn_getPalabra(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos)
{
	char bufferPalabra[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getPalabra(bufferPalabra,sizeof(bufferPalabra)) == 0 && strnlen(bufferPalabra,sizeof(bufferPalabra)) < longitud)
		{
			strncpy(pResultado,bufferPalabra,longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

/* ******************************************************************************************************************************** */
int ValidarNumero(char numero[])
{
   int valido = 1;
   for(int i = 0; i < strlen(numero); i++)
   {
	  if(numero[i] < '0' || numero[i] > '9')
	  {
		  valido = 0;
	  }
   }
   return valido;
}

/* ******************************************************************************************************************************** */
int PedirEntero(char mensaje[])
{
    char auxiliar[10];
    int numeroIngresado;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);

    while(ValidarNumero(auxiliar)==0)
    {
       // printf("%s", mensajeError);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
    }
     numeroIngresado=atoi(auxiliar);

    return numeroIngresado;
}

/* ********* */
/* ******************************************************************************************************************************** */
void get_ValidarInt(int* input, char message[],char eMessage1[],char eMessage2[], int lowLimit, int hiLimit)
{
    char bufferNumStr[200];
    int bufferNum;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", bufferNumStr);

    while(validarNumero(bufferNumStr) == 0)
    {
        printf("%s", eMessage1);
        fflush(stdin);
        scanf("%s", bufferNumStr);
    }

    bufferNum = atoi(bufferNumStr);

    while(validarRangoEntero(bufferNum,lowLimit,hiLimit) == 0)
    {
        printf("%s", eMessage2);
        fflush(stdin);
        scanf("%d", &bufferNum);
    }
    *input = bufferNum;
}

/* ******************************************************************************************************************************** */
int validarRangoEntero(int dato,int lowLimit ,int hiLimit)
{
    int valido = 1;

    if(dato<lowLimit || dato>hiLimit)
    {
       valido = 0;
    }

    return valido;
}

/* ******************************************************************************************************************************** */
int validarNumero(char* numberStr)
{
    int valido=1;
    for(int i=0;i<strlen(numberStr);i++)
    {
	  if(numberStr[i] < '0' || numberStr[i] > '9')
	  {
		  valido=0;
	  }
    }
   return valido;
}

/* ******************************************************************************************************************************** */
int validarNombre(char* cadena,int length)
{
    int retorno=1;
    if(cadena !=NULL && length>0)
    {
        for(int i=0; cadena[i]!='\0' && i<length; i++)
        {
            if( (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != ' ')
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

/* ******************************************************************************************************************************** */
void pedirNombre(char texto[],char textoError[],int max, char input[])
{
    char auxiliar[500];

    printf("%s", texto);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);


    while(!validarNombre(auxiliar, max) || strlen(auxiliar) > max-1)
    {
        printf("%s", textoError);
        fflush(stdin);
        scanf("%[^\n]", auxiliar);
    }
    strcpy(input, auxiliar);

}
