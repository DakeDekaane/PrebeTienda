#include <stdio.h>
#include <stdlib.h>

enum boolean{false,true};

typedef struct Nodo {
	char *nombreProducto;
	int cantidad;
	float precio;
	struct Nodo* siguiente;
}Nodo;

Nodo* inicio=NULL;	//Inicio de cola
Nodo* final=NULL;	//Final de cola

Nodo* crearNodo(char *nombreProducto, int cantidad, float precio) {
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->sucesor = NULL;
	nuevo->antecesor = NULL;
	nuevo->nombreProducto = nombreProducto;
	nuevo->cantidad = cantidad;
	nuevo->precio = precio;
	return nuevo;
}

enum boolean ListaVacia() {
	if(inicio == NULL && final == NULL) return true;
	else return false;
}

//Inserta nodo al final de la lista.
void InsertaNodo(Nodo* nodo) {
	if(ListaVacia()) {
		inicio = nodo;
		final = nodo;
		nodo->siguiente = NULL;
	}
	else {
		final->siguiente = nodo;
		final = nodo;
	}
}

//Remueve elemento por nombre.
Nodo* RemueveNodo(char *nombre) {
	printf("codigo\n");
}