#ifndef editorial_h_INCLUDED
#define editorial_h_INCLUDED

#endif

typedef struct
{
    int   idLibro;
    char  titulo[50];
    char  autor[50];
    float precio;
    char  editorial[50];
}eLibros;

eLibros* new();
eLibros* setters(char* idLibro,char* titulo, char* autor, char* precio, char* editorial);

void mapPrecio(void* this);
int  mostrarLibros(eLibros* this);
int  getters(eLibros* this, int* idLibro, char* titulo, char* autor, float* precio, char* editorial);

int setId(eLibros* this,int idLibro);
int getId(eLibros* this,int* idLibro);

int setTitulo(eLibros* this,char* titulo);
int getTitulo(eLibros* this,char* titulo);

int setAutor(eLibros* this,char* autor);
int getAutor(eLibros* this,char* autor);

int setPrecio(eLibros* this,float precio);
int getPrecio(eLibros* this,float* precio);

int setIdEditorial(eLibros* this,char* editorial);
int getIdEditorial(eLibros* this,char* editorial);

int ordenrPorID(void* datoA, void* datoB);
int ordenarPorAutor(void* punteroA, void* punteroB);


