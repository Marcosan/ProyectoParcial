#include "miLista.h"
#include <stdlib.h>
/*Definicion de funciones sobre la lista*/

extern int Lista_Inicializar(ListaEnlazada *lista){
	lista->ancla.objeto = NULL;
	lista->ancla.siguiente = NULL;
	lista->ancla.anterior = NULL;
	lista->numeroElementos = 0;
	return 1;
}

extern int Lista_Vacia(ListaEnlazada *lista){ //revisar
	if (lista->numeroElementos == 0)
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
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista));
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
	nuevo_elemento->objeto = objeto;

	if (lista->numeroElementos == 0){
		*(nuevo_elemento->siguiente) = lista->ancla;
		*(nuevo_elemento->anterior) = lista->ancla;
		lista->ancla.siguiente = nuevo_elemento;
		lista->ancla.anterior = nuevo_elemento;
	} else{
		*actual = lista->ancla;
		for (int i = 0; i <= lista->numeroElementos; i++){
			if (actual->siguiente->objeto == NULL){
				actual->siguiente = nuevo_elemento;
				nuevo_elemento->anterior = actual;
				*nuevo_elemento->siguiente = lista->ancla;
				(lista->ancla).anterior = nuevo_elemento;
				lista->numeroElementos++;
				return 1;
			}
			actual = actual->siguiente;
		}
		
	}
	
  	return 0;
}
extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista));
	nuevo_elemento->objeto = objeto;
	//strcpy(nuevo_elemento->objeto, objeto);
	nuevo_elemento->anterior = &(lista->ancla);
	nuevo_elemento->siguiente = lista->ancla.siguiente;
	lista->ancla.siguiente = nuevo_elemento;
  	lista->numeroElementos++;
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
	return lista->ancla.anterior;
}
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	return 0;
}
