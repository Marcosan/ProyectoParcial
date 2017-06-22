#include "miLista.h"
#include <stdlib.h>
/*Definicion de funciones sobre la lista*/

extern int Lista_Inicializar(ListaEnlazada *lista){
	lista->ancla.siguiente = NULL;
	lista->ancla.anterior = NULL;
	lista->numeroElementos = 0;
	return 0;
}

extern int Lista_Vacia(ListaEnlazada *lista){
	return 0;
}
extern int Lista_Conteo(ListaEnlazada *lista){
	return 0;
}

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	return 0;
}

/*Funciones de modificacion de la lista*/
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *nuevo_elemento;
	if ((nuevo_elemento = alloc (nuevo_elemento)) == NULL)
		return -1;
	strcpy (nuevo_elemento->objeto, objeto);
	nuevo_elemento->siguiente = NULL;
	nuevo_elemento->anterior = lista->fin;
	lista->fin->siguiente = nuevo_elemento;
	lista->fin = nuevo_elemento;
	lista->tamaño++;
  return 0;
}
extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){
	return 0;
}
extern void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	
}
extern void Lista_SacarTodos(ListaEnlazada *lista){
	
}
extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	return 0;
}
extern int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	return 0;
}


/*Funciones que devuelven un elemento particular de la lista*/
extern ElementoLista *Lista_Primero(ListaEnlazada *lista){
	return 0;
}
extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista){
	return 0;
}
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}