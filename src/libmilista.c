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

extern int Lista_Vacia(ListaEnlazada *lista){
	//printf("esta vacia\n");
	for(ElementoLista *it = lista->ancla.siguiente; it->objeto != NULL; it = it->siguiente){
		free(it);
		lista->numeroElementos--;
	}
	if (lista->numeroElementos == 0){
		lista->ancla.siguiente = NULL;
		lista->ancla.anterior = NULL;

		return 1;
	}
	
	return 0;
}
extern int Lista_Conteo(ListaEnlazada *lista){
	return (int)lista->numeroElementos;
}

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
	*actual = lista->ancla;
	for (int i = 0; i <= lista->numeroElementos; i++){
		if (actual->objeto == objeto){
			return actual;
		}
		
		actual = actual->siguiente;
	}
	return NULL;
}

/*Funciones de modificacion de la lista*/
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista));
	nuevo_elemento->objeto = objeto;
	//printf("%d\n", nuevo_elemento->objeto);

	if (lista->numeroElementos == 0){
		nuevo_elemento->siguiente = &lista->ancla;
		nuevo_elemento->anterior = &lista->ancla;
		lista->ancla.siguiente = nuevo_elemento;
		lista->ancla.anterior = nuevo_elemento;
		lista->numeroElementos++;
	} else{
		ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
		*actual = lista->ancla;
		for (int i = 0; i <= lista->numeroElementos; i++){
			if (actual->siguiente == &lista->ancla){
				actual->siguiente = nuevo_elemento;
				nuevo_elemento->anterior = actual;
				nuevo_elemento->siguiente = &lista->ancla;
				lista->ancla.anterior = nuevo_elemento;
				lista->numeroElementos++;
				//printf("%d\n", i);
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
	if (lista->numeroElementos == 0){
		nuevo_elemento->siguiente = &lista->ancla;
		nuevo_elemento->anterior = &lista->ancla;
		lista->ancla.siguiente = nuevo_elemento;
		lista->ancla.anterior = nuevo_elemento;
		lista->numeroElementos++;
	} else{
		ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
		actual = lista->ancla.siguiente;
		nuevo_elemento->anterior = &(lista->ancla);
		nuevo_elemento->siguiente = actual;
		lista->ancla.siguiente = nuevo_elemento;
		actual->anterior = nuevo_elemento;
	  	lista->numeroElementos++;
	}  	return 0;
}
extern void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	elemento->anterior->siguiente = elemento->siguiente;
	elemento->siguiente->anterior = elemento->anterior;
	lista->numeroElementos--;
}
extern void Lista_SacarTodos(ListaEnlazada *lista){
	//printf("%d\n", lista->numeroElementos);
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
	ElementoLista *next = (ElementoLista*)malloc(sizeof(ElementoLista));
	actual = lista->ancla.siguiente;
	next = actual->siguiente;
	while (actual != &lista->ancla){
		free(actual);
		lista->numeroElementos--;
		actual = (ElementoLista*)malloc(sizeof(ElementoLista));
		actual = next;
		if (actual == &lista->ancla){
			return;
		}
		
		next = next->siguiente;
	}
}
extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista));
	actual = lista->ancla.siguiente;
	nuevo_elemento->objeto = objeto;
	for (int i = 0; i <= lista->numeroElementos; i++){
		if (actual == elemento){
			ElementoLista *next = (ElementoLista*)malloc(sizeof(ElementoLista));
			next = actual->siguiente;
			actual->siguiente = nuevo_elemento;
			nuevo_elemento->anterior = actual;
			nuevo_elemento->siguiente = next;
			next->anterior = nuevo_elemento;
			lista->numeroElementos++;
			//printf("%d\n", i);
			return 1;
		}else{
			if (actual->siguiente == &lista->ancla){
				Lista_InsertarFin(lista,objeto);
				return 1;
			}
		}
		
		actual = actual->siguiente;
	}
	return 0;
}
extern int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista));
	actual = lista->ancla.siguiente;
	nuevo_elemento->objeto = objeto;
	for (int i = 0; i <= lista->numeroElementos; i++){
		if (actual == elemento){
			ElementoLista *ant = (ElementoLista*)malloc(sizeof(ElementoLista));
			ant = actual->anterior;
			ant->siguiente = nuevo_elemento;
			nuevo_elemento->anterior = ant;
			nuevo_elemento->siguiente = actual;
			actual->anterior = nuevo_elemento;
			lista->numeroElementos++;
			//printf("%d\n", i);
			return 1;
		}else{
			if (actual->anterior == &lista->ancla){
				Lista_InsertarInicio(lista,objeto);
				return 1;
			}
		}
		
		actual = actual->siguiente;
	}
	return 0;
}


/*Funciones que devuelven un elemento particular de la lista*/
extern ElementoLista *Lista_Primero(ListaEnlazada *lista){
	ElementoLista *tmp = &lista->ancla;
	if (lista->numeroElementos == 0){
		return NULL;
	}
	return tmp->siguiente;
}
extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista){
	return lista->ancla.anterior;
}
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	if (lista->numeroElementos == 0 || elemento == NULL 
		|| (elemento->siguiente == &lista->ancla)){
		return NULL;
	}
	return elemento->siguiente;
}
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	if (lista->numeroElementos == 0 || elemento == NULL 
		|| (elemento->anterior == &lista->ancla)){
		return NULL;
	}
	return elemento->anterior;
}
