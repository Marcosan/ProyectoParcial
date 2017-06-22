#include "miLista.h"
#include <stdlib.h>
/*Definicion de funciones sobre la lista*/

extern int Lista_Inicializar(ListaEnlazada *lista){
	lista = (ListEnlazada*) malloc(sizeof(ListaEnlazada)); // agregar memoria
	lista->ancla.siguiente = NULL;
	lista->ancla.anterior = NULL;
	lista->numeroElementos = 0;
	return 0;
}

extern int Lista_Vacia(ListaEnlazada *lista){ //revisar
	if lista->numeroElementos == 0
		return 1;
	
	return 0;
}
extern int Lista_Conteo(ListaEnlazada *lista){
	return 0;
}

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	return 0;
}

/*Funciones de modificacion de la lista*/
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){//me parece que te olvidas del ancla revisa la funcion de abajo
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
	ElementoLista *nuevo_elemento;
	if ((nuevo_elemento = alloc (sizeof(nuevo_elemento))) == NULL)
		return -1;
	nuevo_elemento->objeto = objeto;
	//strcpy(nuevo_elemento->objeto, objeto);
	nuevo_elemento->anterior = &(lista->ancla);
	nuevo_elemento->siguiente = lista->ancla.siguiente;
	lista->ancla.siguiente = nuevo_elemento;
  	lista->tamaño++;
  	return 0;
}
extern void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	
}
extern void Lista_SacarTodos(ListaEnlazada *lista){
	
}
extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	ElementoLista *nuevo_elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
	if (nuevo_elemento == NULL){
		return -1;
	}

	nuevo_elemento->objeto = objeto;

	for(ElementoLista *it = lista->ancla.siguiente; it != NULL; it = it->siguiente){ //itera en la lista 
		if(it == elemento){ 							 //compara el iterador con la variable de entrada
			nuevo_elemento->siguiente = it->siguiente;
			nuevo_elemento->anterior = it;
			it->siguiente->anterior = nuevo_elemento;
			it->siguiente = nuevo_elemento;
			return 1;
		}
	}
	return 0;
}
extern int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	return 0;
}


/*Funciones que devuelven un elemento particular de la lista*/
extern ElementoLista *Lista_Primero(ListaEnlazada *lista){
	return lista->ancla.siguiente;
}
extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista){
	return lista->ancla.anterior
}
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}
