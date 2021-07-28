#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_loadFromBinary(char* path , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_saveAsBinary(char* path , LinkedList* pArrayList);
int menuDeOpciones();

#endif // Controller_H_INCLUDED
