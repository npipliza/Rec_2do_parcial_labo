#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;

	    this = (LinkedList*) malloc(sizeof(LinkedList));//construye cabecera/pFirstNode
	    if(this != NULL)
	    {
	    	this -> size = 0; //da valor 0 al tamaño
	    	this -> pFirstNode = NULL; //lo apunta a null
	    }
	    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
       returnAux = this -> size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL)
	{
		if(nodeIndex >= 0 && nodeIndex < ll_len(this))
		{
			pNode = this -> pFirstNode; // se accede a la cabecera/pFistNode

			while(nodeIndex > 0)//itera hasta llegar al nodo 1
			{
				pNode = pNode -> pNextNode;
				nodeIndex --;
			}
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	newNode = (Node*) malloc(sizeof(Node));//creo nodo

    	if(newNode != NULL)//une el nodo ultimo, anterior al null con el que se crea
    	{
    		newNode -> pElement  = pElement; //elemento del parametro
    		newNode -> pNextNode = NULL; // pos para pisar

    		if(nodeIndex == 0)//idem, pero si solo existe la cabecera, crea nodo1
    		{
    			newNode -> pNextNode = this -> pFirstNode;
    			this -> pFirstNode = newNode;
    		}
    		else
    		{
    			newNode -> pNextNode = getNode(this,nodeIndex);
    			(getNode(this, nodeIndex-1)) -> pNextNode = newNode;
    		}

    		this -> size ++;//si esta ok aumenta el tamaño de la lista
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);// agrega nodo al final
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    Node* pNode;//aux
    void* returnAux = NULL;

     if(this != NULL)
    {
       if( index >= 0 && index < ll_len(this))
       {
            pNode = getNode(this,index);//toma el nodo con los parametros

            if(pNode != NULL)
            {
               returnAux = pNode -> pElement;//retorna el dato cargado en buffer
            }
       }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    Node* pNode;
    int returnAux = -1;
    int len       = ll_len(this);

    if(this != NULL && index > -1 && index < len)
    {
        pNode = getNode(this, index);//toma el nodo con los parametros

        if(pNode != NULL)
        {
            pNode -> pElement = pElement;//guarda el elemento pasado por parametro
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux     = -1;
    Node* pNodeAux    = NULL;
    Node* pNodeAuxSup = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
    {
           pNodeAux = getNode(this,index);//nodo a eliminar

           if(pNodeAux != NULL)
           {
               if(index == 0)
               {
                   this -> pFirstNode = pNodeAux -> pNextNode;//pone en null al pFirstNode
               }
               else
               {
                   pNodeAux              = getNode(this, index -1);//nodo anterior
                   pNodeAuxSup           = pNodeAux -> pNextNode;//paso el valor
                   pNodeAux -> pNextNode = pNodeAuxSup -> pNextNode;//hace el reemplazo
               }

               free(pNodeAuxSup);//limpia la memoria
               this -> size --;//achico la lista
               returnAux = 0;
           }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
    	len = ll_len(this);

		//for(int i = 0; i < len; i ++)
		for(i = len -1; i >= 0; i --)
		{
			ll_remove(this, i);//llamo a ll_remove para eliminar los elementos
		}
		//this -> size --;
		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)//lista por parametro para liberar todas las posiciones
    	{
    		free(this);//libero la lista
    	}
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux    = -1;
    void* auxElement = NULL;
    int len;

    len = ll_len(this);

    if(this != NULL && len > 0)
    {
    	for(int i = 0; i < len; i ++)
    	{
    		auxElement = ll_get(this, i);// igualo a la pos i de la lista

    		if(auxElement == pElement)//busco el nodo con el pElemento igual al buscado
    		{
    			returnAux = i;
    			break;// corto la iteracion cuando encuentra el igual
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;//existe y tiene elementos

    	if(ll_len(this) == 0)//si es igual a 0 esta vacia y retorna 1 ok
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = addNode(this, index, pElement);//Agrega un nodo en el index pasado como parametro

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);//ubica el elemento a eliminar
    	ll_remove(this, index);//elimina el elemento
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
      {
    	returnAux = 0;// retorna 0 si no contiene el elemento

		if(ll_indexOf(this, pElement) != -1)//busca elemento y retorna posicion si exite
		{
			returnAux = 1;//si el retorno es 0 o mayor, existe elemento
		}
      }
    return returnAux;

}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement;
   	int len2 = ll_len(this2);


   	if(this != NULL && this2 != NULL)
   	{
   		returnAux = 1;

   		for(int i = 0; i < len2; i++)//recorre this2
   		{
   			auxElement = ll_get(this2, i);//toma el elemento

   			if(!ll_contains(this, auxElement)) //verifica si el elemento de this2 esta en this
   			{
   				returnAux = 0;
   				break;
   			}
   		}
   	}
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* pElementAux;

    if(this != NULL && from >= 0 && from <= len && to > from && to <= len)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
       		for(int i = from; i < to; i++)//recorre para clonar
       		{
       			pElementAux = ll_get(this, i);
       			ll_add(cloneArray, pElementAux);
       		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int from = 0;
    int to   = ll_len(this);

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, from, to);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int   returnAux  = -1;
    void* elementAux = NULL;
	void* elementI   = NULL;
	void* elementJ   = NULL;
	int len;


	if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		len = ll_len(this);

		for(int i = 0; i < len -1; i ++)
		{
			for(int j = i +1; j < len; j++)
			{
				elementI = ll_get(this, i);
				elementJ = ll_get(this, j);

				if((order == 1 && pFunc(elementI,elementJ) > 0) ||(order == 0 && pFunc(elementI,elementJ) < 0))
				{
					elementAux = elementI;
					ll_set(this,i,elementJ);  //elementI = elementJ;
					ll_set(this,j,elementAux);//elementJ = elementAux;
				}
			}
		}
	   returnAux = 0;
	}
	return returnAux;
}
/**********************************************************************/

/** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    void* filterList = NULL;  //Inicializo el puntero filterList en NULL
    if (this != NULL && pFunc != NULL )
    {
        filterList = ll_newLinkedList();    //Le asigno a filterList un nuevo linkedList
        if (filterList != NULL)
        {
            for (int i=0; i<ll_len(this); i++)
            {
                if (pFunc(ll_get(this, i)))                  //Condicional de la funcion a escoger
                    ll_add(filterList, ll_get(this, i));    //Asigna empleados del linkedList a la nueva lista
            }
        }
    }
    return filterList;
}

/** \brief Hace una lectura de la LinkedList item por item
 *
 * \param this El puntero a la LinkedList
 * \param int El retorno de la funcion
 * \return -1 si hay error, 0 si salio todook
 *
 */
LinkedList* ll_map(LinkedList* this, void (*fn)(void* pElement))
{
    void* mapList = NULL;
    if (this != NULL)
    {
        mapList = ll_newLinkedList();
        if (mapList != NULL)
        {
            for (int i=0; i<ll_len(this); i++)
            {
                void* aux = (LinkedList*)ll_get(this, i);
                fn(aux);
                ll_add(mapList, aux);
            }
        }
    }
    return mapList;
}











////////
///
///
/*
int ll_count(LinkedList* this, int (fn)(void element))
{
	int len=ll_len(this);
	int acumulador=0;
	void* elemento;
	if(this!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			elemento=ll_get(this,i);
			acumulador+=fn(elemento);
		}
	}
	return acumulador;
}*/
/**
 * @fn LinkedList ll_filter*(LinkedList*, int()(void))
 * @brief
 * La función “ll_filter” recibirá una lista y una función criterio “fn”.
 * Se deberá iterar todos los elementos de la lista y pasarlos a la función “fn”.
 * La función “fn” devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse.
 *  La función “ll_filter” generará la nueva lista resultado, agregará a la misma los ítems correspondientes y
 *  la devolverá.
 *
 * @param this
 * @param fn
 * @return
 */
/*
LinkedList* ll_filter(LinkedList* this, int (fn)(void element))
{
	int len=ll_len(this);
	LinkedList* cloneArray=NULL;
	void* elemento;
	if(this!=NULL)
	{
		cloneArray=ll_newLinkedList();
		for(int i=0;i<len;i++)
		{
			elemento=ll_get(this,i);
			if(fn(elemento)==1)
			{
				ll_add(cloneArray,ll_get(this,i));
			}
		}
	}
	return cloneArray;
}
*/
