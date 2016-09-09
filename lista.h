#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum boolean{false,true};

typedef struct Nodo {
	char nombreProducto[20];
	int cantidad;
	float precio;
	struct Nodo* siguiente;
}Nodo;

Nodo* inicio=NULL;
Nodo* final=NULL;

Nodo* crearNodo(char nombreProducto[], int cantidad, float precio) {
	Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->siguiente = NULL;
	strcpy(nuevo->nombreProducto,nombreProducto);
	nuevo->cantidad = cantidad;
	nuevo->precio = precio;
	return nuevo;
}

enum boolean ListaVacia() {
	if(inicio == NULL && final == NULL) return true;
	else return false;
}

//Inserta nodo al final de la lista.
void InsertaProducto(Nodo* nodo) {
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
Nodo* RemueveProducto(char nombreProducto[]) {
	//Si la lista está vacía.
	if(ListaVacia()) {
		return (Nodo*)NULL;
	}
	Nodo* aux = inicio;
	//Si la lista tiene un sólo elemento.
	if (inicio == final && strcmp(aux->nombreProducto,nombreProducto) == 0 ) {
		inicio = NULL;
		final = NULL;
		return aux;
	}
	else{
		Nodo* scout = inicio;
		while( strcmp(scout->nombreProducto,nombreProducto) != 0 ) {
			scout = scout->siguiente;
			if(scout == NULL) return NULL;
		}
		
		while(aux->siguiente != scout) {
			aux = aux->siguiente;
		}
		aux->siguiente = scout->siguiente;
		return scout;
	}
}

void BuscaProducto(char nombreProducto[]) {
	if(ListaVacia()) {
		printf("Lista Vacía.\n");
	}
	else {
		int opcion;
		Nodo* scout = inicio;
		while( strcmp(scout->nombreProducto,nombreProducto) != 0 ) {
			scout = scout->siguiente;
			if (scout == NULL) {
				printf("Producto \"%s\" no encontrado.\n",nombreProducto);
				return;
			}
		}
	printf("Nombre: %s\t Cantidad: %d\tPrecio: %.2f\n",scout->nombreProducto,scout->cantidad,scout->precio);	
	}
}

void ImprimeInventario() {
	//Si la lista está vacía.
	if(ListaVacia()) {
		printf("Lista Vacía.\n");
	}
	else {
		Nodo* aux = inicio;
		printf(" Nombre \t Cantidad \t Precio\n");
		while(aux != NULL) {
			if(strlen(aux->nombreProducto) <= 6) 
				printf(" %s\t\t    %d\t\t %.2f\n",aux->nombreProducto,aux->cantidad,aux->precio);
			else
				printf(" %s\t    %d\t\t %.2f\n",aux->nombreProducto,aux->cantidad,aux->precio);
			aux = aux->siguiente;
		}	
	}
}

void ModificaInventario(char nombreProducto[]) {
	//Si la lista está vacía.
	if(ListaVacia()) {
		printf("Lista Vacía.\n");
	}
	else {
		int opcion;
		Nodo* scout = inicio;
		while( strcmp(scout->nombreProducto,nombreProducto) != 0 ) {
			scout = scout->siguiente;
			if (scout == NULL) {
				printf("Producto \"%s\" no encontrado.\n",nombreProducto);
				return;
			}
		}
		printf("¿Qué desea modificar?\n1. Cantidad\n2. Precio\nIngrese una opción: ");
		scanf("%d",&opcion);
		switch(opcion) {
			case 1:
				printf("Ingrese nueva cantidad: ");
				scanf("%d",&(scout->cantidad));
				break;
			case 2:
				printf("Ingrese nuevo precio: ");
				scanf("%f",&(scout->precio));
				break;
			default:
				printf("Opción inválida.");
				break;
		}
	}
}

void CargaInventario() {
	FILE* inventario = fopen("Productos.txt","r");
	if (!inventario) {
		printf("Error al cargar inventario. Verifique el archivo.\n");
		return;
	}
	Nodo* aux = inicio;
	char nombreProducto[20];
	int cantidad;
	float precio;	
	
	while(!feof(inventario)){
		fscanf(inventario,"%s %d %f\n",nombreProducto,&cantidad,&precio);
		InsertaProducto(crearNodo(nombreProducto,cantidad,precio));
	}
}

void GuardaInventario() {
	FILE* inventario = fopen("Productos.txt","w");
	if (!inventario) {
		printf("Error al guardar el inventario. Verifique el archivo.\n");
		return;
	}
	Nodo* aux = inicio;
	while(aux != NULL){
		fprintf(inventario,"%s %d %.2f\n",aux->nombreProducto,aux->cantidad,aux->precio);
		aux = aux->siguiente;
	}

}
