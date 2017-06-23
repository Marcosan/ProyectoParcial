#include "miLista.h"
#include <stdlib.h>
/*Definicion de funciones sobre la lista*/

extern int Lista_Inicializar(ListaEnlazada *lista){
	lista->ancla.objeto = NULL;                    //inicializamos el apuntador del ancla
	lista->ancla.siguiente = NULL;			//inicializamos el apuntador a siguiente
	lista->ancla.anterior = NULL;			//inicializamos el apuntador a anterior
	lista->numeroElementos = 0;			//inicialmente la lista esta vacia
	return 1;
}

extern int Lista_Vacia(ListaEnlazada *lista){
	//printf("esta vacia\n");
	for(ElementoLista *it = lista->ancla.siguiente; it->objeto != NULL; it = it->siguiente){  //iteramos dentro de la lista con la variable it
		free(it);				//liberamos la memoria de cada elemento
		lista->numeroElementos--;		//reducimos los numeros de elemntos de la lista
	}
	if (lista->numeroElementos == 0){		//si el numero de elemetos dentro de la lista es 0
		lista->ancla.siguiente = NULL;		//reseteamos los apuntadores del ancla
		lista->ancla.anterior = NULL;

		return 1;
	}
	
	return 0;
}
extern int Lista_Conteo(ListaEnlazada *lista){
	return (int)lista->numeroElementos;			//retorna el valor del numero de elemntos
}

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista)); //se crea un nuevo ElementoLista y se asigna memoria
	*actual = lista->ancla;
	for (int i = 0; i <= lista->numeroElementos; i++){			//se itera sobre la lista
		if (actual->objeto == objeto){					//se compara el elemnto de la lista con el elemento introducido para buscar
			return actual;
		}
		
		actual = actual->siguiente;
	}
	return NULL;
}

/*Funciones de modificacion de la lista*/
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
	ElementoLista *nuevo_elemento = (ElementoLista*)malloc(sizeof(ElementoLista)); //se crea un nuevo elemento y se asigna memoria
	nuevo_elemento->objeto = objeto;
	//printf("%d\n", nuevo_elemento->objeto);

	if (lista->numeroElementos == 0){			//si la lista esta vacia
		nuevo_elemento->siguiente = &lista->ancla;	//se le asigna la posisicion del ancla ya que sera el primer elemnto de la lista
		nuevo_elemento->anterior = &lista->ancla;	//como es el primer elemento este estara rodeado por el ancla
		lista->ancla.siguiente = nuevo_elemento;	//el apuntador del ancla.siguiente sera al nuevo elemento
		lista->ancla.anterior = nuevo_elemento;		//el apuntador del ancla.anterior sera el nuevo elemento ya que sera el primer elemento
		lista->numeroElementos++;			//aumento el numero de elementos de la lista
	} else{							//caso contrario
		ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista)); //creo el elemento actual y asigno memoria
		*actual = lista->ancla;
		for (int i = 0; i <= lista->numeroElementos; i++){			//recorremos la lista segun el numero de elemntos
			if (actual->siguiente == &lista->ancla){
				actual->siguiente = nuevo_elemento;
				nuevo_elemento->anterior = actual;
				nuevo_elemento->siguiente = &lista->ancla;		//el apuntador siguiente de nuevo elemento  debe ubicar a la posicion del ancla
				lista->ancla.anterior = nuevo_elemento;			//el apuntador del ancla anterior debera ser el nuevo elemnto ya que se lo agrega al final
				lista->numeroElementos++;				//aumento el numero de los elemntos de la lista
				//printf("%d\n", i);
				return 1;
			}
			
			actual = actual->siguiente;
		}
	}
	
  	return 0;
}
extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){                      //se realiza lo mismo de la funcion anterior solo que ahora al principio
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
	elemento->anterior->siguiente = elemento->siguiente;			//se re-asignan los apuntadores del elemento a eliminar
	elemento->siguiente->anterior = elemento->anterior;
	lista->numeroElementos--;						//se reduce el numero de elemntos de la lista
}
extern void Lista_SacarTodos(ListaEnlazada *lista){				//vaciara la lista
	//printf("%d\n", lista->numeroElementos);
	ElementoLista *actual = (ElementoLista*)malloc(sizeof(ElementoLista));   //se cre el elemnto actual y se asigna memoria
	ElementoLista *next = (ElementoLista*)malloc(sizeof(ElementoLista));	//se crea el elemento next y se asigna memoria
	actual = lista->ancla.siguiente;					//se inicializa actual con el primer valor de la lista
	next = actual->siguiente;						//se inicializa con  el siguiente valor de actual
	while (actual != &lista->ancla){					//mientras actual sea diferente de la posicion del ancla
		free(actual);							//liberamos mememoria de actual
		lista->numeroElementos--;					//reducimos el numero de elementos de la lista
		actual = (ElementoLista*)malloc(sizeof(ElementoLista));		
		actual = next;
		if (actual == &lista->ancla){					//si actual es igual a la posicion del ancla 
			return;							//no hace nada y sale
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
	ElementoLista *tmp = &lista->ancla;					//se crea un elemento temporal y se le asigna la direccion de memoria del ancla
	if (lista->numeroElementos == 0){     					//si la laista esta vacia
		return NULL;							//retorna null
	}
	return tmp->siguiente;							//retorna el elemento siguiente al que apunta el ancla
}
extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista){			
	return lista->ancla.anterior;						//retorna el elemento anterior al ancla
}
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	if (lista->numeroElementos == 0 || elemento == NULL 
		|| (elemento->siguiente == &lista->ancla)){			//para estos casos no existira elemento siguiente
		return NULL;
	}
	return elemento->siguiente;
}
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
	if (lista->numeroElementos == 0 || elemento == NULL 			//para estos casos no existira elemento anterior
		|| (elemento->anterior == &lista->ancla)){
		return NULL;
	}
	return elemento->anterior;
}
